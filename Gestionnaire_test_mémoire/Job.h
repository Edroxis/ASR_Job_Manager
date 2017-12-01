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
        int pid;

    protected:
	string name;

    public:
        Job(const char * processName);
	Job();
        int launch();
        virtual int run() = 0;
        int pause();
        int resume();
        int getPid();
	int killProcess();

	//Ajout destructeur virtuel !!!
};

#endif

//Stratégie classe startégie: choose index to kill, ..... avec en paramètre le vect
//Méthode Stratégie virtuel pour pouvoir la redéfinir si jamais (méthode que choisit le max pour la mémoire)


