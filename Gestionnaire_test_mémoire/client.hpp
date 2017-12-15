#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

#define BUF_SIZE 256
#define RESPONSE_SIZE 64

class Client{
	private:
	int         sockfd;
	int         len;
	sockaddr_un address;
	int         result;
	std::string command;
	char        response[RESPONSE_SIZE];
	const char* sock_name;

	public:
	Client(const char* sn){
		sock_name = sn;
	}

	void send(char* str){
		//std::cout << sock_name << std::endl;

		sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

		address.sun_family = AF_UNIX;
		strcpy(address.sun_path, sock_name);
		len = sizeof(address);

		result = connect(sockfd, (sockaddr*)&address, len);

		if(result == -1)
		{
			perror("Error: Client can't connect!");
		}

		std::string tmp = std::string(str);

		// Write command from stdin in the socket
		write(sockfd, tmp.c_str(), tmp.length());

		// Read and print main program response
		//read(sockfd, response, RESPONSE_SIZE);
		//std::cout << response << std::endl;

		close(sockfd);
	}
};
