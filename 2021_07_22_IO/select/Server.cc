#include "SelectServer.hpp"

void Usage(string proc)
{
    cout << "Usage:\n\t" << proc << " port" << endl;
}
int main(int argc, char *argv[])
{
    cout << sizeof(fd_set) * 8 << endl;
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }
    SelectServer *ssvr = new SelectServer(atoi(argv[1]));
    ssvr->InitServer();
    ssvr->Start();

    delete ssvr;
    return 0;
}
