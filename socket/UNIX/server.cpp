#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

struct SockAddrUn{
	sa_family_t sun_family;
	char sun_path[108];
};

using namespace std;

int main(int argc, char *argv[]){
	const struct SockAddrUn* addr = new SockAddrUn;
	int fd = socket(AF_UNIX, SOCK_STREAM, 0);
	char path[108];

	if(fd == 0) cout << "UNIX Socket successfully created";
	else{
		cout << "UNIX Socket creation failure";
		return 1;
	}

	strcpy(addr->sun_path, "/tmp/lmaj/serv.socket");
	addr->sun_family = AF_UNIX;

	if(bind(fd, addr) == 0) cout << "Bind success";
	else{
		cout << "Bind Failure";
		return 1;
	}

	return 0;
}
