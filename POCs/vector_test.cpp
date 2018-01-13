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
	// Define the jobs
	Command cmd1 = Command("./infinite_job.sh proc1");
	Command cmd2 = Command("./infinite_job.sh proc2");
	Job1 job1 = Job1();

	// Define the vector
	vector<Job*> job_list;

	// Put the Jobs on the vector
	job_list.push_back(&cmd1);
	job_list.push_back(&cmd2);
	job_list.push_back(&job1);

	// Launch Jobs
	job_list[0]->launch();
	job_list[1]->launch();
	job_list[2]->launch();

	// Stop all but the 1st
	job_list[1]->pause();
	job_list[2]->pause();

	// Each 2s, stop running job and resume the next one
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
