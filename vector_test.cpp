#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <iostream>
#include <vector>
#include "command.hpp"
#include "job1.hpp"

using namespace std;

int main( int argc, char* argv[] ){
	Command cmd1 = Command("./infinite_job.sh proc1");
	Command cmd2 = Command("./infinite_job.sh proc2");
	Job1 job1 = Job1();
	vector<Job*> job_list;

	job_list.push_back(&cmd1);
	job_list.push_back(&cmd2);
	job_list.push_back(&job1);

	job_list[0]->launch();
	job_list[1]->launch();
	job_list[2]->launch();
	
	//Command mycmd1 = *((Command*)job_list[0]);
	//Command mycmd2 = *((Command*)job_list[1]);
	
	//mycmd1.launch();
	//mycmd2.launch();

	/*mycmd2.pause();
	while(1){
		sleep(2);
		mycmd1.pause();
		mycmd2.resume();
		sleep(2);
		mycmd1.resume();
		mycmd2.pause();
	}*/

	job_list[1]->pause();
	job_list[2]->pause();
	while(1){
		sleep(2);
		job_list[0]->pause();
		job_list[1]->resume();
		sleep(2);
		job_list[1]->pause();
		job_list[2]->resume();
		sleep(2);
		job_list[2]->pause();
		job_list[0]->resume();
	}
	return 0;
}
