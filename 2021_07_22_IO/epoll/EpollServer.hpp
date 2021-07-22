#include "Sock.hpp"

#define SIZE 64
// 每一个sock都应该有一个bucket，包括缓冲区 buffer，读取的位置记录pos,其文件描述符
class bucket
{
    public:
        char buffer[20];
        int pos;
        int fd;
        bucket(int sock)
          :fd(sock),pos(0)
        {
            memset(buffer, 0, sizeof(buffer));
        }
        ~bucket()
        {
          
        }
};
// select poll 只支持水平触发 LT 
// epoll 支持水平触发 和 边缘触发(ET)
class EpollServer{
    private:
        int lsock; // 监听套接字
        int port;  // 端口号
        int epfd;  // epoll 模型的文件描述符，指向一个epoll结构体，结构体里有红黑树和双向链表，这些机制使得epoll模型非常高效
    public:
        EpollServer(int _p = 8081):port(_p)
        {}
        void InitServer()
        {
            lsock = Sock::Socket();
            Sock::Setsockopt(lsock);
            Sock::Bind(lsock, port);
            Sock::Listen(lsock);

            epfd = epoll_create(256);// 创建函数模型
            if (epfd < 0)
            {
                cerr << "epoll_create error " << endl;
                exit(5);
            }
            cout << "listen sock : " << lsock << endl;
            cout << "epoll    fd : " << epfd  << endl;
        }
        // 将套接字和事件加入到 epoll 模型中
        void AddEventToEpoll(int sock, uint32_t event)
        {
            struct epoll_event ev;
            ev.events = event;
            if (sock == lsock)
            {
                ev.data.ptr = nullptr;
            }
            else 
            {
                ev.data.ptr = new bucket(sock);
            }
            // 用epoll 模型的第二个借口 epoll_ctl 将事件和套接字加入到epoll模型中
            epoll_ctl(epfd, EPOLL_CTL_ADD, sock, &ev);
        }
        void DelEventFromEpoll(int sock)
        {
            close(sock);
            epoll_ctl(epfd, EPOLL_CTL_DEL, sock, nullptr);
        }

        void  HandlerEvents(struct epoll_event revs[],int num)
        {
            for (int i = 0; i < num; i++)
            {
                uint32_t ev = revs[i].events;
                if (ev & EPOLLIN) // 读事件就绪
                {
                    if (revs[i].data.ptr != nullptr) // 通信套接字
                    {
                         bucket *bp = (bucket*)revs[i].data.ptr;
                         // 把这个套接字的 bucket 拿出来进行读取
                         ssize_t s = recv(bp->fd, bp->buffer + bp->pos, sizeof(bp->buffer) - bp->pos, 0);
                         if (s > 0)
                         {
                            bp->pos += s;
                            cout << "client# " << bp->buffer << endl;
                            if (bp->pos >= sizeof(bp->buffer))
                            {
                                struct epoll_event temp;
                                temp.events = EPOLLOUT;
                                temp.data.ptr = bp;
                                epoll_ctl(epfd, EPOLL_CTL_MOD, bp->fd, &temp);
                            }
                         }
                         else if (s == 0)
                         {
                            // 数据读完，短连接
                            DelEventFromEpoll(bp->fd);
                            delete bp;
                         }
                         else 
                         {
                            // 读出错，抛异常什么的
                         }
                    }
                    else // 监听套接字 
                    {
                        int sock = Sock::Accept(lsock);
                        if (sock > 0)
                        {
                            AddEventToEpoll(sock, EPOLLIN); // 将新获得的通信套接字放到 epoll 模型里
                        }
                    }
                }
                else if (ev & EPOLLOUT) // 写事件就绪
                {

                }
                else 
                {
                  // 其他事件就绪
                }
            }
        }
        void Start()
        {
            // 首先将监听套接字加到epoll模型里
            // 用户告诉内核你要帮我关心这个监听套接字上是否其他连接来的事件就绪，这个事件也是读事件
            AddEventToEpoll(lsock, EPOLLIN);
            int timeout = -1; // 阻塞等
            struct epoll_event revs[SIZE];// 等待就绪事件放到这个数组中
            for (;;)
            {
                int num = epoll_wait(epfd, revs, SIZE, timeout);
                switch(num)
                {
                    case 0:
                      cout << "time out ..." << endl;
                      break;
                    case -1:
                      cerr << "epoll_wait error" << endl;
                      break;
                    default:
                      HandlerEvents(revs,num);
                      break;
                }
            }
        }
        ~EpollServer()
        {
            close(lsock);
            close(epfd);
        }
};
