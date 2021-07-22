#pragma once 
#include "Sock.hpp"

#define DFL_PORT 8080
#define NUM (sizeof(fd_set) * 8)
#define DFL_FD -1

class SelectServer
{
    private:
        int lsock;
        int port;
        int fd_array[NUM];
    public:
        SelectServer(int _p = DFL_PORT)
          :port(_p)
        {}
        void InitServer()
        {
            for (int i = 0; i < NUM; i++)
            {
                fd_array[i] = DFL_FD;
            }
            lsock = Sock::Socket();
            Sock::Setsockopt(lsock);
            Sock::Bind(lsock, port);
            Sock::Listen(lsock);

            fd_array[0] = lsock;
        }
        void AddFdToArray(int sock)
        {
            int i = 0;
            for (;i < NUM; i++)
            {
                if (fd_array[i] == DFL_FD)
                  break;
            }
            if (i >= NUM)
            {
                cerr << "fd array is full, close sock" << endl;
                close(sock);
            }
            else 
            {
                fd_array[i] = sock;
                cout << "fd: " << sock << "add to select ..." << endl;
            }
        }

        void DelFdFromArray(int index)
        {
            if (index >= 0 && index < NUM)
              fd_array[index] = DFL_FD;
        }
        void HandlerEvents(fd_set * rfds)
        {
            for (int i = 0; i < NUM; i++)
            {
                if (fd_array[i] == DFL_FD)
                {
                    continue;
                }
                if (FD_ISSET(fd_array[i],rfds))
                {
                    // 连接事件就绪
                    if (fd_array[i] == lsock)
                    {
                        // 有连接事件
                        int sock = Sock::Accept(lsock);
                        if (sock >= 0)
                        {
                            // 
                            cout << "get a new link ..." << endl;
                            AddFdToArray(sock);
                        }
                    }
                    else 
                    {
                        // 读数据事件就绪
                        char buf[1024];
                        ssize_t s = recv(fd_array[i], buf, sizeof(buf), 0);
                        if (s > 0)
                        {
                            buf[s] = 0;
                            cout << "client# " << buf << endl;
                        }
                        else if (s == 0)
                        {
                            cout << "client quit " << endl;
                            close(fd_array[i]);
                            DelFdFromArray(i);
                        }
                        else 
                        {
                            // 读出错
                        }
                    }
                }
            }
        }
        void Start()
        {
            int maxfd = DFL_FD;
            for (;;)
            {
                fd_set rfds;
                FD_ZERO(&rfds);
                cout << "fd_array : ";
                for (int i = 0; i < NUM; i++)
                {
                    if (fd_array[i] != DFL_FD)
                    {
                        cout << fd_array[i] << " ";
                        FD_SET(fd_array[i], &rfds);
                        if (maxfd < fd_array[i])
                        {
                            maxfd = fd_array[i];
                        }
                    }
                }
                cout << endl;
                cout << "begin select ..." << endl;
                //
                switch(select(maxfd + 1,&rfds, nullptr, nullptr,nullptr))
                {
                    case 0:
                      cout << "time out ..." << endl;
                      break;
                    case -1:
                      cerr << "select error!" << endl;
                      break;
                    default: 
                      HandlerEvents(&rfds);
                      break;

                }
            }
        }
        ~SelectServer()
        {
            close(lsock);
        }
};
