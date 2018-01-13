#include "job.hpp"

class Job1 : public Job{
	int run(){
		int i = 0;
		while(1){
			std::cout << "coucou, job " << getpid() << " (" << i << ")" << std::endl;
			i++;
		}
	}
};
