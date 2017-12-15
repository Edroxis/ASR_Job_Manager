#include "Job.h"
using namespace std;

Job::Job(const char* processName): pid(0), name(processName)
{
    //pid=0;
    //name= processName;
}

Job::Job(Job * job1){
	pid= job1->getPid();
	name= job1->getName();
}
Job::Job()
{
    pid=0;
	name="default";
}

int Job::launch(){

   cout << "command running" << endl;
   pid = fork();

   if(pid == 0){
		run();
        exit(1);
    }

    return 0;
}


int Job::pause(){
    kill(pid, SIGSTOP);
    return 0;
}

string Job::getName(){
	return name;
}

int Job::resume(){
    kill(pid, SIGCONT);
	return 0;
}

int Job::getPid()
{
    return pid;
}

int Job::killProcess(){
	kill(pid, SIGKILL);
	return 0;
}

Job::~Job(){

}
