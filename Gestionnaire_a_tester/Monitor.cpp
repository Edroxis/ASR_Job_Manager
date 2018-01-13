
#include "Monitor.h"
using namespace std;



/**
*\brief create a new monitor with the max  and the min of the system charge
*\param min the minal charge of the system
*\param max the maximal charge of the system
*/
Monitor::Monitor(float min, float max){
	levelMin=min;
	levelMax=max;
}


/**
*\brief get the percent of CPU charge which is free
*\return the percent of free CPU charge
*/
float Monitor::getCPUCharge(void){

    string line;
    string data[12];
    int i=0;
    long int freeCpu=0;
    long int busyCPU=0;

    //read the file /proc/stat
    ifstream read("/proc/stat");
    if(read)
    {
	//Read the first line
        getline(read,line);
        string delimiter = " ";
        size_t pos = 0;
        string token;
	//Split all the value of the line
        while ((pos = line.find(delimiter)) != string::npos && i<12) {
            token = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            data[i]=token;
            i++;
        }
	//Compute the free cpu charge and the busy cpu charge
        freeCpu=atoi(data[5].c_str())+atoi(data[6].c_str());
        busyCPU= atoi(data[2].c_str())+ atoi(data[3].c_str())+atoi(data[4].c_str())+atoi(data[7].c_str())+atoi(data[8].c_str())+atoi(data[9].c_str());
        read.close();
     }
     //return the pourcent of free cpu charge
    float pourcentCPU=((float)freeCpu/(freeCpu+busyCPU))*100;
    return pourcentCPU;
}

/**
*\brief get the percent of memory which is free
*\return the percent of free memory
*/
float Monitor::getMemCharge(void){
    string line;
    int i=0;
    int j=0;
    string data[12];
    long int freeMemory=0;
    long int totalMemory=0;
    ifstream read("/proc/meminfo");
    float pourcentMem=0;
    if(read)
    {
               while(getline(read,line)){
		   //Get Mem total on the first line
                   if(j==0){
                       string delimiter = ":";
                       i=0;
                       size_t pos = 0;
                       string token;
                       while ((pos = line.find(delimiter)) != string::npos) {
                           token = line.substr(0, pos);
                           line.erase(0, pos + delimiter.length());
                           data[i]=token;
                           totalMemory=atoi(line.c_str());
                           i++;
                       }
                   }
		  //Get free Mem on the third line
                   if (j==2){
                       string delimiter = ":";
                       i=0;
                       size_t pos = 0;
                       string token;
                       while ((pos = line.find(delimiter)) != string::npos) {
                           token = line.substr(0, pos);
                           line.erase(0, pos + delimiter.length());
                           data[i]=token;
                           freeMemory=atoi(line.c_str());
                           i++;
                       }
                   }
                   j++;

               }
		//Compute the percent of free memory
               pourcentMem=((float)freeMemory/totalMemory)*100;
               read.close();
   }
   return pourcentMem;
}

/**
*\brief Get the action that the system has to do
*/
string Monitor::ActionSystem(){
    clock_t delay = clock();
    float cpuCharge= 0;
    float memCharge=0;
    while(1){

	//Get busy CPU and memory charge
	cpuCharge= 100-getCPUCharge();
    memCharge=100-getMemCharge();
	cout<<"charge cpu: "<<cpuCharge<<endl;
	cout<<"charge mem: "<<memCharge<<endl;
		
		//The CPU charge is to high
        if(cpuCharge> levelMax){
            return "-cpu";
        }
		//The mem charge is to high
 		else if(memCharge>levelMax){
			return "-mem";
		}
		//It's possible to launch more process
        else if (cpuCharge<levelMin&&memCharge<levelMin){
			//Get the time
            clock_t delay = clock();
            clock_t endDelay = clock();
			//Check if the cpu and the mem charge is low for 5 min
            while((clock()-delay)<5 && cpuCharge<levelMin && memCharge<levelMin){
                endDelay=clock();
                cpuCharge= getCPUCharge();
                memCharge=getMemCharge();
            }
			//Check if the cpu and the mem charge is low for 5 min
            if(endDelay-delay >=5){
                return "+";
            }
        }

    }
}

