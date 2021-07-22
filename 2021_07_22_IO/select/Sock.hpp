#pragma once 
#include <iostream>
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/select.h>

using namespace std;

class Sock
{
    public:
       static int Socket()
       {
          int sock = socket(AF_INET, SOCK_STREAM, 0);
          if (sock < 0)
          {
              cerr << "socket error " << endl;
              exit(2);
          }
          return sock;
       }
       static void Bind(int sock, int port)
       {
          struct sockaddr_in local;
          bzero(&local, sizeof(local));

          local.sin_family = AF_INET;
          local.sin_port = htons(port);
          local.sin_addr.s_addr = INADDR_ANY;

          if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
          {
              cerr << "bind error" << endl;
              exit(3);
          }
       }
       static void Listen(int sock)
       {
          if (listen(sock, 5) < 0)
          {
              cerr << "listen error" << endl;
              exit(4);
          }
       }

       static int Accept(int sock)
       {
          struct sockaddr_in peer;// 对端信息
          socklen_t len = sizeof(peer);
          int fd = accept(sock, (struct sockaddr*)&peer, &len);
          if (fd < 0)
          {
              cerr << "accept error" << endl;
          }
          return fd;
       }
       // 表示允许创建端口号相同但是IP地址不同的多个 socket 描述符
       // 解决服务器 TIME_WAIT 导致的重启服务器进而发生绑定失败的问题
       static void Setsockopt(int sock)
       {
          int opt = 1;
          setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
       }
};
