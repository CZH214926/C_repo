#include "EpollServer.hpp"

int main()
{
    EpollServer *es = new EpollServer(8081);
    es->InitServer();
    es->Start();
    delete es;
    return 0;
}
