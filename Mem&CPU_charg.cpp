#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<signal.h>
#include <cstdlib>
#include <string.h>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] ){
	string chargeCPU;
	float chargeCPUNonUtilise;
	long int memoireLibre;
	long int memoireTotal;
	float pourcentageMemoireLibre;
	string chargeMemoire;
	string res;
	string line;
	FILE *in;
	char buff[512];
	 
	if(!(in = popen("top -n1 | grep 'Mem'| awk '{print $8;}'", "r"))){
	        return 1;
	}
	 
	while(fgets(buff, sizeof(buff), in)!=NULL){
		memoireLibre=atoi(buff);
	}
	pclose(in);
	cout<<"Mémoire Libre: "<<memoireLibre<<endl;

	if(!(in = popen("top -n1 | grep 'Mem'| awk '{print $4;}'", "r"))){
	        return 1;
	}
	 
	while(fgets(buff, sizeof(buff), in)!=NULL){
		memoireTotal=atoi(buff);
	}
	pclose(in);
	cout<<"Mémoire totale: "<<memoireTotal<<endl;

	pourcentageMemoireLibre= memoireTotal-memoireLibre/*100-(((memoireTotal-memoireLibre)/memoireTotal)*100);*/;
	cout<<"Pourcentage de memoire libre: "<< pourcentageMemoireLibre << " % "<<endl;

	if(!(in = popen("top -n1 | grep 'Cpu(s)'| awk '{print $8;}'", "r"))){
	        return 1;
	}
	 
	while(fgets(buff, sizeof(buff), in)!=NULL){
		char *get= strchr ( buff, ',' );
		*get='.';
		chargeCPUNonUtilise=atof(buff);	
	}
	pclose(in);

	cout <<"Espace CPU non utilisé: "<< chargeCPUNonUtilise<<endl;
	system("top -n1 -b>test.txt"); // execute the UNIX command "ls -l >test.txt"
	ifstream read("test.txt");
	if(read)
	{
		int i=0;
		while(getline(read,line)&& i<4)
		{
			if(i==2)
			{
				chargeCPU=line;	
			}
			if(i==3)
			{
				chargeMemoire=line;
			}
			i++;
		}
		cout <<"Charge CPU: "<< chargeCPU<<endl;
		cout<<"Charge mémoire: "<<chargeMemoire<<endl;
		read.close();
	}
	
	return 0;
}
