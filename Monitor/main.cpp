#include"CPU_charge.h"
#include <sstream>
#include <string>


int main( int argc, char* argv[] ){


	int     fd[2], nbytes;
        pid_t   childpid;
        char    readbuffer[80];


        pipe(fd);

	//fork error
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

	//Child process
        if(childpid == 0)
        {
                // Close the input of the pipe for the child
                close(fd[0]);
		Monitor charge;
		
		while(1){
			//Get CPU charge
			float chargeCPU =charge.getCPUCharge();
			char array[6];
			sprintf(array, "%f", chargeCPU);	

			//Get Mem charge
			char array2[6];
			float chargeMem =charge.getMemCharge();
			sprintf(array2, "%f", chargeMem);
		
			// Format it "CPU charg/MemCharg
			string chargeInfo=array;
			chargeInfo+="/";
			chargeInfo+=array2;
			
			cout<<"Lu :"<<chargeInfo<<endl;

		        // Send the charge through the output side of pipe
		        write(fd[1], chargeInfo.c_str(), chargeInfo.size()+1);
			
			sleep(1);
		}
                exit(0);
        }
	//Parent process
        else
        {
                //Close the output of the pipe
                close(fd[1]);
		
		while(1){
		        //Read the charge from the pipe
		        nbytes = read(fd[0], readbuffer, sizeof(readbuffer));

			//Get the Mem charge eand the CPU charge
			string delimiter= "/";
			string res= readbuffer;
			size_t pos = 0;
			pos=res.find(delimiter);
			float chargeCPU=atof(res.substr(0,pos).c_str());
			res.erase(0, pos+delimiter.length());
			float chargeMem=atof(res.c_str());

			cout <<"Charge CPU : "<<chargeCPU<<endl;
			cout<<"Charge Mémoire : "<<chargeMem<<endl;
		}
		
        }

	
    return 0;
}


