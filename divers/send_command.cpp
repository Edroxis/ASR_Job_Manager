#include "client.hpp"

int main()
{
	Client cli = Client("/tmp/server_socket");
	std::string str;

	// Get String on std::cin
	getline(std::cin, str);

	// Transform to char*
	char* cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());

	//std::cout << str << std::endl;
	cli.send(cstr);
	//std::cout << "init Client socket OK" << std::endl;
	delete [] cstr;
}
