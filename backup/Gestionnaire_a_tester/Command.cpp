#include "Command.h"
/**
*\brief Constructor
*\params str the command 
*/
Command::Command(const char * str){
		
		//cmd = std::string(str);
		//get the name of the command
		name=str;
		//std::cout << "this is your string: " << cmd << std::endl;
		//Get the arguments of the command
		build_argv(str);
		for(int j=0; argv[j] != 0; j++){
			std::cout<< argv[j] << std::endl;
		}
	}
/**
*\brief get the argument of the command
*\params str the command
*/
void Command::build_argv(const char * str){
		
		//Get the nb of args
		int nb = calc_nb_elements(str);
		//std::cout << "nb elements:" << nb << std::endl;
		argv = new char*[nb+1];
		int res_index = 0;
		std::string * tmp = new std::string();
		//Get the arguments
		for(;*str != 0; str++){
			//std::cout << *str;
			if(*str != ' ') *tmp+=*str;
			else{
				char * tmp2 = new char[tmp->size()+1];
				std::copy(tmp->begin(),tmp->end(),tmp2);
				argv[res_index] = tmp2;
				res_index++;
				//std::cout << *tmp << std::endl;
				tmp = new std::string();
			}
		}
		char * tmp2 = new char[tmp->size()+1];
		std::copy(tmp->begin(),tmp->end(),tmp2);
		argv[res_index] = tmp2;
		//std::cout << tmp << std::endl;
		res_index++;

		argv[res_index] = (char*) 0;
		//std::cout << std::endl << "res content:" << std::endl;
}

/**
*\brief compute the number of arguments of the command
*\params str the command 
*\return the number of arguments
*/
int Command::calc_nb_elements(const char * str){
		int i=0;
		for(; *str != 0; str++){
			if(*str==' ') i++;
		}
		return i+1;
}

/**
*\brief launch the command
*\return 0
*/
int Command::run(){
		execvp(argv[0], argv);
		exit(1);
	}
