#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

class Command{
	public:
	int pid;
	std::string cmd;
	Command(const char * str){
		cmd = std::string(str);
		std::cout << "this is your string: " << cmd << std::endl;
		pid = -1;
	}

	int run_cmd(){
		std::cout << "command running" << std::endl;
		pid = fork();
		int j=0;
		
		if(pid == 0){
			system(cmd.c_str());
			//while(1){}
			exit(1);
		}
		
		return 0;
	}

	int pause(){
		std::string command_base = std::string("kill -STOP ");
		
		// PID to String
		std::ostringstream oss;
     		oss << pid;
     		std::string pid_str = oss.str();
		
		// Build command to stop this process
		const char * command_to_execute = (command_base + pid_str).c_str();
		std::cout << "Stopping process " << pid_str << std::endl;
		std::cout << command_to_execute << std::endl;
		system(command_to_execute);
		return 0;
	}

	int resume(){
		std::string command_base = std::string("kill -CONT ");
		
		// PID to String
		std::ostringstream oss;
     		oss << pid;
     		std::string pid_str = oss.str();
		
		// Build command to stop this process
		const char * command_to_execute = (command_base + pid_str).c_str();
		std::cout << "Resuming process " << pid_str << std::endl;
		std::cout << command_to_execute << std::endl;
		system(command_to_execute);
		return 0;
	}
};
