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
	Command cmd1 = Command("./infinite_job.sh proc1");
	Command cmd2 = Command("./infinite_job.sh proc2");
	cmd1.launch();
	//cmd2.launch();
	//cmd2.pause();
	while(1){
		sleep(5);
		cmd1.pause();
		//cmd2.resume();
		sleep(5);
		cmd1.resume();
		//cmd2.pause();
	}
	return 0;
}
