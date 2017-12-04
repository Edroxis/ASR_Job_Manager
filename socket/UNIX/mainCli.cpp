#include "client.hpp"

int main()
{
	Client cli = Client("server_socket");
	std::cout << "init Client socket OK" << std::endl;
	cli.send("hello world!");
}
