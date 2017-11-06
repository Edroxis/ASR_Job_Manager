
#include <sstream>
#include <string>
#include "Gestionnaire.h"
#include "Command.h"



int main( int argc, char* argv[] ){

    Gestionnaire gestionnaire;
    Command cmd1 = Command("./infinite_job.sh proc1");
	Command cmd2 = Command("./infinite_job.sh proc2");
    gestionnaire.add(&cmd1);
    gestionnaire.add(&cmd2);
    gestionnaire.launch();
    return 0;
}


