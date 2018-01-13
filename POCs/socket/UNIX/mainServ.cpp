#include "server.hpp"

int main()
{
	Server srv = Server("server_socket");
	while(1){
		srv.receive();
		std::cout << srv.getline() << std::endl;
	}
}
