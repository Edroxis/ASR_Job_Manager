#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<signal.h>

using namespace std;

int main( int argc, char* argv[] ){
	cout << "hello world" << std::endl;

	int pid = fork();

	if(pid == 0){
		cout << "Hello! I'm child, my pid is " << getpid() << " and my father's is " << getppid() << std::endl;
		for(int i=0; i<100000000; i++){
			//cout << "child said " << i << std::endl;
		}
	}
	else if(pid > 0){
		sleep(1);
		cout << "Hello! I'm father, child process is: " << pid << ", prepare to die!" << std::endl;
		cout << "Father: KILL IT WITH FIRE" << std::endl;
		kill(pid, SIGKILL);
		cout << "Father: Finally..." << std::endl;
	}
	else{
		cerr << "Unable to fork" << std::endl;
	}

	return 0;
}
