#include "Server.hpp"
     
int main(int argc , char **argv)  
{
    if (argc < 3)
        return (1);

    int port = atoi(argv[1]);
    std::string pass = argv[2];

    Server server(port, pass);
    server.binder();
    server.listener();

    return 0;  
}