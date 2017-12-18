#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<signal.h>

using namespace std;

int main( int argc, char* argv[] ){
	//char * args[] = {"/bin/ls", "-r", "-l", (char *) NULL};
	//execv("/bin/ls", args);

	int pid = fork();

	// Child process, run infinite job
	if(pid == 0){
		std::cout << "Child process id: " << getpid() << std::endl;
		char * args[] = {"./infinite_job.sh", "proc1", (char *) NULL};
		execv("./infinite_job.sh", args);
      	}
	// Parent Process, kill child after 5s
	else{
		std::cout << "Father process id: " << getpid() << std::endl;
		sleep(5);
		kill(pid, SIGKILL);
	}

	//char * args[] = {"/bin/ls", "-l", (char *) NULL};
	//execv("/bin/ls", args);

	return 0;
}
