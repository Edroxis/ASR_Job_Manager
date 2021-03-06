#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Job.h"
#include"Monitor.h"
#include "Command.h"
#include "Strategie.h"
#include "Server.h"

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
	    //level min
	    int min;
	    //level max
	    int max;
	    //if the "to Execute list is used
	    bool isUsed;


	public:

         Gestionnaire(int levelMin, int levelMax);
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
		// Get the command to launch from the shell
		void getCommandToLaunch();
		//launch the server that allow to get all the command form the shell 
	    int startServer();
		~Gestionnaire();
};
