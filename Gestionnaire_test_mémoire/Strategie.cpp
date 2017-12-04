#include "Strategie.h"

Job* Strategie::strategieDefault(vector<Job*> running){
		return running[0];	
}

Job* Strategie::strategieMemMax(vector<Job*> running){

	string line;
	Job* jobToPause;
	int maxMem=0;	

	for (unsigned i=0; i<running.size(); ++i)
    {
		string chemin1="/proc/";
		stringstream ss;
		ss << running[i]->getPid();
		string str = ss.str();
		chemin1+=str+"/statm";


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


