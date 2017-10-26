#ifndef JOB
#define JOB 0


#include<iostream>
#include<signal.h>
#include<unistd.h>
#include <cstdlib>

using namespace std;

class Job{

    private:
        int pid;

    public:
        Job();
        int launch();
        virtual int run() = 0;
        int pause();
        int resume();
        int getPid();
};

#endif
