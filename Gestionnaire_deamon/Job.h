#ifndef JOB
#define JOB 0


#include<iostream>
#include<signal.h>
#include<unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Job{

    private:
	//pid of the job
        int pid;

    protected:
	//Name of the job
	string name;
	int running;

	Job();

    public:
        Job(const char * processName);
	Job(Job * job1);
	//launch the job
        int launch();
	//Code to execute
        virtual int run() = 0;
	//Pause the process
        int pause();
	//Resume the process
        int resume();
	//get the process pid
        int getPid();
	//kill a job
	int killProcess();
	//Get the name of the job
	string getName();
	//Get running status
	int isRunning();

	virtual ~Job();

};

#endif
