#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Job.h"
#include"Monitor.h"
#include "Command.h"

using namespace std;

class Gestionnaire {

    private:

        vector<Job*> toExecute;
        vector<Job*> running;

	public:
        Gestionnaire();
        int add(Job* job);
        int add(Command* command);
        int launch();
        void printVector();
        void launchProcess();

};
