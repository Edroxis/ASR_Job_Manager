#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

#define BUF_SIZE 256

class Server {
	private:
		int         	server_sockfd;
		int         	client_sockfd;
		int         	server_len;
		unsigned int	client_len;
		sockaddr_un 	server_address;
		sockaddr_un 	client_address;
		char		buffer[BUF_SIZE];

	public:
		Server(const char * sock_name);
		void receive();
		char * getline();
};
