#include "Strategie.h"
/**
*\brief Default strategie
*\param running the list of the process 
*\return the job to kill/pause/launch
*/
Job* Strategie::strategieDefault(vector<Job*> running){
	//Return the first element of the list
	return running[0];	
}

/**
*\brief get the process which used the most memory
*\param running the list of the process 
*\return the job to kill
*/
Job* Strategie::strategieMemMax(vector<Job*> running){

	string line;
	Job* jobToPause;
	int maxMem=0;	
	//For each process launch
	for (unsigned i=0; i<running.size(); ++i)
    {
		//Get to "/proc/pid/statm"
		string chemin1="/proc/";
		stringstream ss;
		ss << running[i]->getPid();
		string str = ss.str();
		chemin1+=str+"/statm";

		//Read the memory used and check if it's the max
        ifstream read(chemin1.c_str());
		if (read)
		{
			getline(read, line);
			int value=atoi(line.c_str());
			if(value>maxMem)
			{
				maxMem=value;
				jobToPause= running[i];
			}
		}
    }
	return jobToPause;
}


