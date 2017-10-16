#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<signal.h>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class Monitor {
	public:
		//Get the CPU charge
		float getCPUCharge();
		//Get Mem charge 
		float getMemCharge();
};
