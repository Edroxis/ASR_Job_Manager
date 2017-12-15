#include "client.hpp"

int main()
{
	Client cli = Client("server_socket");
	cli.send("hello world!");
	cli.send("wassup?");
	//std::cout << "init Client socket OK" << std::endl;
}
