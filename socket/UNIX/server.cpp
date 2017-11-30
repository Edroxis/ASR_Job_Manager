// Original source: https://cygwin.com/ml/cygwin/2000-08/msg00784.html

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

#define BUF_SIZE 256

int main()
{
    int         server_sockfd;
    int         client_sockfd;
    int         server_len;
    unsigned int         client_len;
    sockaddr_un server_address;
    sockaddr_un client_address;
    char buffer[BUF_SIZE];

    // Close socket if still active
    unlink("server_socket");

    // Init new socket
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "server_socket");
    server_len = sizeof(server_address);
    bind(server_sockfd, (sockaddr*)&server_address, server_len);

    listen(server_sockfd, 5);
    while(true)
    {
        std::cout << "server waiting" << std::endl;

        client_sockfd = accept(server_sockfd,
                        (sockaddr*)&client_address,
                        &client_len);

	// Read characters on socket (max=BUF_SIZE)
        int nb_chars_read = read(client_sockfd, buffer, BUF_SIZE);

	// Zero Terminated String
	buffer[nb_chars_read] = 0;
	std::cout << buffer << std::endl;
	//std::cout << nb_chars_read << std::endl;

	// Send response and close socket
	write(client_sockfd, "Gestionnaire: Command Received!", 31);
        close(client_sockfd);
    }
}
