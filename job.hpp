#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

class Job{
        public:
        int pid;
        
	Job(){}

        int launch(){
                std::cout << "command running" << std::endl;
                pid = fork();
                
                if(pid == 0){
			run();
			exit(1);
                }

                return 0;
        }

	virtual int run() = 0;

        int pause(){
		kill(pid, SIGSTOP);
		return 0;
	}

        int resume(){
                kill(pid, SIGCONT);
		return 0;
        }
};
