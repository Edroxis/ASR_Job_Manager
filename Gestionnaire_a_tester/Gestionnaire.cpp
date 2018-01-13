#include "Gestionnaire.h"

/**
*\brief consrtuctor
*\params levelMin the level minimum
*\params levelMax the level maximum
*/
Gestionnaire::Gestionnaire(int levelMin, int levelMax)
{
	min=levelMin;
	max=levelMax;

}

/**
*\brief add a job
*\params job the job to add
*\return 0
*/
int Gestionnaire::add(Job* job)
{
    toExecute.push_back(job);
    return 0;
}

/**
*\brief add a command
*\params command the command to add
*\return 0
*/
int Gestionnaire::add(Command* command)
{
    toExecute.push_back(command);
    return 0;
}

/**
*\brief print all the vector
*/
void Gestionnaire::printVector(){

    //Process to execute
    cout<<"To execute"<<endl;
    for (unsigned i=0; i<toExecute.size(); ++i)
        cout << ' ' << toExecute[i]->getPid()<<endl;

    //Process killed
    cout<<"Running"<<endl;
    for (unsigned i=0; i<running.size(); ++i)
        cout << ' ' << running[i]->getPid()<<endl;
}

/**
*\brief launch the manager
*\return 0
*/
int Gestionnaire::launch()
{
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
		Monitor monitor (min,max);


		while(1){

            string res=monitor.ActionSystem();
            // Send the charge through the output side of pipe
            write(fd[1], res.c_str(), res.size()+1);
			sleep(1);
		}
        exit(0);
    }
	//Parent process
    else
    {
        //Close the output of the pipe
        close(fd[1]);
        launchProcess();
		while(1){
            //Read the charge from the pipe
            nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
			string res= readbuffer;
			cout<<"Lu: "<<res<<endl;

            //Add process in running and remove it from toExecute
            if(res=="+")
            {
                /*if(toExecute.empty()==false)
                {
                    cout<<"Ajoute"<<endl;
                    running.push_back(toExecute[toExecute.size()-1]);
                    toExecute[toExecute.size()-1]->resume();
                    toExecute.pop_back();
                    printVector();
                }*/

				if(toExecute.empty()==false){
                    //get the process to launch
					Job* jobToLaunch= strategie.strategieDefault(toExecute);
					for (int i=0; i<toExecute.size(); i++)
					{
                        //if it's the good process launch it
						if (toExecute[i]->getPid()==jobToLaunch->getPid())
						{
							running.push_back(toExecute[i]);
							toExecute[i]->resume();
							toExecute.erase(toExecute.begin()+i);

						}
					}

				}
				
            }

            //Add process in toExecute and remove it from running
            else if(res=="-cpu")
            {
				
                /*if(running.empty()==false)
                {
                    cout<<"Enleve"<<endl;
                    toExecute.push_back(running[running.size()-1]);
                    running[running.size()-1]->pause();
                    running.pop_back();
                    printVector();
                }*/
				if(running.empty()==false){
                    //Get the job to pause
					Job* jobToPause= strategie.strategieDefault(running);
					for (int i=0; i<running.size(); i++)
					{
                        //If it's the good process launch it
						if (running[i]->getPid()==jobToPause->getPid())
						{
							toExecute.push_back(running[i]);
							running[i]->pause();
							running.erase(running.begin()+i);
						}
					}
				}
            }
	        else if (res=="-mem")
			{
			    //Get the process to kill
				if(running.size()>0){

					Job* jobToPause= strategie.strategieMemMax(running);
					cout<<"========================================================================="<<endl;
					cout<<"Attention !: Le processus "<<jobToPause->getName()<<" a été tué car il consommait trop de memoire !"<<endl;
					cout<<"========================================================================="<<endl;
					for (int i=0; i<running.size(); i++)
					{
		            //Remove it from running
						if (running[i]->getPid()==jobToPause->getPid())
						{
							running.erase(running.begin()+i);
						}
					}
		        	//Kill the process
					killed.push_back(jobToPause);
					jobToPause->killProcess();
				}
			}
		}
    }
    return 0;
}

/**
*\brief launch all of the process then pause them
*/
void Gestionnaire::launchProcess()
{
    for (unsigned i=0; i<toExecute.size(); ++i)
    {
        toExecute[i]->launch();
        toExecute[i]->pause();
    }
}
