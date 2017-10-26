#include<iostream>
#include<unistd.h>
#include<signal.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Monitor {

	private:
		float levelMin;
		float levelMax;

	public:

		Monitor(float min=25, float max=95);
		//Get the CPU charge
		float getCPUCharge();
		//Get Mem charge
		float getMemCharge();
		//Tell the administrator what to do
		string ActionSystem();
};
