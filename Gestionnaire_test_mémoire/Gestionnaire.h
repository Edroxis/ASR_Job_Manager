#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Job.h"
#include"Monitor.h"
#include "Command.h"
#include "Strategie.h"

using namespace std;

class Gestionnaire {

    private:
	//Jobs to Execute
        vector<Job*> toExecute;
	//Jobs to run
        vector<Job*> running;
	//Jobs killed
	vector<Job*> killed;
	//strategie used
	Strategie strategie;


	public:
        Gestionnaire();
	//Add a job
        int add(Job* job);
	//Add a command 
        int add(Command* command);
	//Launch the manager
        int launch();
	//Print al the vector (for debug)
        void printVector();
	//Launch all the process
        void launchProcess();
	//Job* getProcessToPause();

};
