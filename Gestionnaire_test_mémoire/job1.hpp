#include "job.hpp"

class Job1 : public Job{
	int run(){
		for (int i=0; i<10000; i++){
			double* tab= new double[1000];
			for (int j=0; j<1000; j++){
				tab[j]=j
			}
			double** tab2= new double*[1000];
			for (int j=0; j<1000; j++){
				tab2[j]=j
			}
			for (int j=0; j<1000; j++){
				tab2[j]+=tab[j];
			}

	
		}
	}
};
