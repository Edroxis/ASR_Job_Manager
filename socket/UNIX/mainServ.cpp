#include "server.hpp"

int main()
{
	Server srv = Server("server_socket");
	srv.receive();
	std::cout << srv.getline();
}
