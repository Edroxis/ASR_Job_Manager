#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
#include "job.hpp"

class Command : public Job{
	public:
	char** argv;
	Command(const char * str){
		build_argv(str);

		// Print the command on standard output
		/*for(int j=0; argv[j] != 0; j++){
			std::cout<< argv[j] << " ";
		}
		std::cout << std::endl;*/
	}

	// Builds the argv table
	void build_argv(const char * str){
		int nb = calc_nb_elements(str);

		// Build argv
		argv = new char*[nb+1];

		int res_index = 0;

		// Reserve memory space for our temporary string
		std::string * tmp = new std::string();

		// For each character on the command
		for(;*str != 0; str++){
			// if not a space, add it to temporary string
			if(*str != ' ') *tmp+=*str;
			// if space, save element and change argv index
			else{
				// Reserve memory space for our char*
				char * tmp2 = new char[tmp->size()+1];
				// Copy the temp string on our table
				std::copy(tmp->begin(),tmp->end(),tmp2);
				// Make argv index point to previously allocated char* tmp2
				argv[res_index] = tmp2;
				// Change Index
				res_index++;

				tmp->clear();
			}
		}
		// Same operation for last word of the command
		char * tmp2 = new char[tmp->size()+1];
		std::copy(tmp->begin(),tmp->end(),tmp2);
		argv[res_index] = tmp2;
		res_index++;

		// Terminate our table with a NULL char*
		argv[res_index] = (char*) 0;
	}

	// Counts spaces to know how many elements on command
	int calc_nb_elements(const char * str){
		int i=0;
		for(; *str != 0; str++){
			if(*str==' ') i++;
		}
		return i+1;
	}

	int run(){
		execvp(argv[0], argv);
		exit(1);
	}
};
