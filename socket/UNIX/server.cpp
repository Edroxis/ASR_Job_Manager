// source: https://cygwin.com/ml/cygwin/2000-08/msg00784.html

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

int main()
{
    int         server_sockfd;
    int         client_sockfd;
    int         server_len;
    unsigned int         client_len;
    sockaddr_un server_address;
    sockaddr_un client_address;

    unlink("server_socket");
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "server_socket");
    server_len = sizeof(server_address);
    bind(server_sockfd, (sockaddr*)&server_address, server_len);

    listen(server_sockfd, 5);
    while(true)
    {
        char ch;

        std::cout << "server waiting" << std::endl;

        client_sockfd = accept(server_sockfd,
                        (sockaddr*)&client_address,
                        &client_len);

        read(client_sockfd, &ch, 1);
        std::cout << ch << std::endl;
        ch++;
	write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }
}
