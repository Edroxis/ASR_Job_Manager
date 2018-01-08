#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Job.h"
#include <string>
#include<iostream>
#include<unistd.h>
#include <fstream>


using namespace std;

class Strategie {

	public:

		//Default strategie
    	Job* strategieDefault(vector<Job*> running);
		//Strategie to get the process which used the most memory
		Job* strategieMemMax(vector<Job*> running);

};
