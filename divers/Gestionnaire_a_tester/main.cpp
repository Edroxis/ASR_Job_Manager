
#include <sstream>
#include <string>
#include "Gestionnaire.h"
#include "Command.h"
#include "jobTest.hpp"



int main( int argc, char* argv[] ){
    //Instanciate a new manager
    Gestionnaire gestionnaire(40,50);
    //Create a new command 
    //Command cmd1 = Command("./infinite_job.sh proc1");
	//Command cmd2 = Command("./infinite_job.sh proc2");
    //Create a job
	//Job1 jobe = Job1("test");
    //Add the job and command
    //gestionnaire.add(&cmd1);
    //gestionnaire.add(&cmd2);
	//gestionnaire.add(&jobe);

	JobTest* job1= new JobTest[100]();
	for (int i=0; i<100; i++){
		job1[i]=JobTest ("test");
		gestionnaire.add(&(job1[i]));
	} //=JobTest ("test 1");
	/*JobTest job2 =JobTest ("test 2");
	JobTest job3 =JobTest ("test 3");
	JobTest job4 =JobTest ("test 4");

	gestionnaire.add(&job1);
	gestionnaire.add(&job2);
	gestionnaire.add(&job3);
	gestionnaire.add(&job4);*/

    //Launch everything
    gestionnaire.launch();
    return 0;
}


