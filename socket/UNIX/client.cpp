// source: https://cygwin.com/ml/cygwin/2000-08/msg00784.html

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

#define BUF_SIZE 256
#define RESPONSE_SIZE 64

int main()
{
    int         sockfd;
    int         len;
    sockaddr_un address;
    int         result;
    std::string command;
    char 	response[RESPONSE_SIZE];

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, "server_socket");
    len = sizeof(address);

    result = connect(sockfd, (sockaddr*)&address, len);

    if(result == -1)
    {
        perror("oops:  client1");
        return 1;
    }

    getline(std::cin, command);
    //std::cout << str << std::endl;

    // Write command from stdin in the socket
    write(sockfd, command.c_str(), command.length());

    // Read and print main program response
    read(sockfd, response, RESPONSE_SIZE);
    std::cout << response << std::endl;

    close(sockfd);
    return 0;
}
