#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
#include "job.hpp"

class Command : public Job{
	public:
	std::string cmd;
	Command(const char * str){
		cmd = std::string(str);
		//std::cout << "this is your string: " << cmd << std::endl;
		pid = -1;
	}

	int run(){
		std::cout << "your command is: " << cmd << " with pid: " << getpid() << std::endl;
		char* args[] = {}
		execvp("ls", "ls", "-l", (char*) 0);
		exit(1);
	}
};
