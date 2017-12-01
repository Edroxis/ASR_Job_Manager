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

        char** argv;

	public:

        Command(const char * str);

        void build_argv(const char * str);

        int calc_nb_elements(const char * str);

        int run();
};

#endif
