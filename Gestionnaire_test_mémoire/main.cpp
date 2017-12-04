
#include <sstream>
#include <string>
#include "Gestionnaire.h"
#include "Command.h"
#include "job1.hpp"



int main( int argc, char* argv[] ){

    Gestionnaire gestionnaire;
    Command cmd1 = Command("./infinite_job.sh proc1");
	Command cmd2 = Command("./infinite_job.sh proc2");
	Job1 jobe = Job1("test");
    gestionnaire.add(&cmd1);
    gestionnaire.add(&cmd2);
	gestionnaire.add(&jobe);
    gestionnaire.launch();
    return 0;
}


