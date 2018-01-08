#include "Job.h"
using namespace std;

/**
*\brief constructor
*\param processName the process name 
*/
Job::Job(const char* processName): pid(0), name(processName)
{
    //pid=0;
    //name= processName;
}

/**
*\brief constructor
*\param job1 a job
*/
Job::Job(Job * job1){
	pid= job1->getPid();
	name= job1->getName();
}

/**
*\brief constructor
*/
Job::Job()
{
    pid=0;
	name="default";
}

/**
*\brief launch a job
*/
int Job::launch(){

   cout << "command running" << endl;
   pid = fork();

   if(pid == 0){
		run();
        exit(1);
    }

    return 0;
}

/**
*\brief pause a job
*/
int Job::pause(){
    kill(pid, SIGSTOP);
    return 0;
}

/**
*\brief get the name of the job
*\return 0
*/
string Job::getName(){
	return name;
}

/**
*\brief resume a job
*\return 0
*/
int Job::resume(){
    kill(pid, SIGCONT);
	return 0;
}

/**
*\brief get the pid of a job
*\return the pid
*/
int Job::getPid()
{
    return pid;
}

/**
*\brief kill a process
*\return 0
*/
int Job::killProcess(){
	kill(pid, SIGKILL);
	return 0;
}

/**
*\brief destructor
*/
Job::~Job(){

}
