#include "Job.h"
using namespace std;

Job::Job()
{
    pid=0;
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

int Job::resume(){
    kill(pid, SIGCONT);
	return 0;
}

int Job::getPid()
{
    return pid;
}
