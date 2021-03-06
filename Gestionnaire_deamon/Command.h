#ifndef COMMAND
#define COMMAND 0
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
#include "Job.h"

class Command : public Job{

	private:
	//Command arguments
        char** argv;

	public:
	
        Command(const char * str);
	//Construct the command
        void build_argv(const char * str);
	//Compute the number of arguments of the command
        int calc_nb_elements(const char * str);
	//Launch the command
        int run();
};

#endif
