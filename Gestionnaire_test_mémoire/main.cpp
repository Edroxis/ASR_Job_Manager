
#include <sstream>
#include <string>
#include "Gestionnaire.h"
#include "Command.h"
#include "job1.hpp"



int main( int argc, char* argv[] ){
    //Instanciate a new manager
    Gestionnaire gestionnaire;
    //Create a new command 
    Command cmd1 = Command("./infinite_job.sh proc1");
	Command cmd2 = Command("./infinite_job.sh proc2");
    //Create a job
	Job1 jobe = Job1("test");
    //Add the job and command
    gestionnaire.add(&cmd1);
    gestionnaire.add(&cmd2);
	gestionnaire.add(&jobe);
    //Launch everything
    gestionnaire.launch();
    return 0;
}


