#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <list>
#include <iostream>
#include "command.hpp"

using namespace std;



int main( int argc, char* argv[] ){
	int pid = fork();

        if(pid == 0){
                cout << "Hello! I'm child, my pid is " << getpid() << " and my father's is " << getppid() << std::endl;
                execl("/bin/sh", "sh", "-c", "./infinite_job.sh", (char *) 0);	
                for(int i=1; i<10; i++){
                        i--;
			//execl("monScriptSh", "./inifite_job.sh", (char*) 0);
			//cout << "child said " << i << std::endl;
                }
        }
        else if(pid > 0){
                //execl("/bin/ls", "/bin/ls", "-l", (char *) 0);
		//execl("/home/administrateur/Bureau/ASR_Job_Manager", "./infinite_job.sh", (char *) 0);
		sleep(10);
                //cout << "Hello! I'm father, child process is: " << pid << ", prepare to die!" << std::endl;
                //cout << "Father: KILL IT WITH FIRE" << std::endl;
                kill(pid, SIGKILL);
                //cout << "Father: Finally..." << std::endl;
        }
        else{
                cerr << "Unable to fork" << std::endl;
        }

        return 0;	
	
}

