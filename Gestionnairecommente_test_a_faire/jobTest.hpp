#include <vector>
#include <array>
#include <random>
#include <iostream>
#include <cstdlib>
#include "Job.h"

class JobTest : public Job{
	public:
	JobTest(const char* name) : Job(name)
	{
 		
	}
	JobTest() : Job("test")
	{
 
	}

	int run(){

		unsigned length = atoi("500000"); // 50000
        unsigned memory = atoi("10"); // 10

    	std::array<unsigned,10> nbs;
    	std::vector<char*> pts; pts.reserve(memory*50000);
    	std::default_random_engine rengine;

    	for(unsigned i=0; i<50000; ++i) {

        	for(unsigned wait=0, fin=length; wait<fin; ++wait) ++nbs[rengine()%10];
        	for(unsigned fill=0, fin=memory; fill<fin; ++fill) pts.push_back(new char[1024]);

    	}

    	for(auto n: nbs) std::cout << n << std::endl;
    	for(auto p: pts) delete[] p;

    	return 0;
	}
    
};
//-std=c++11
//-std++11
