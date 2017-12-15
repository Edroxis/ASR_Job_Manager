#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{

}

int Gestionnaire::add(Job* job)
{
    toExecute.push_back(job);
    return 0;
}

int Gestionnaire::add(Command* command)
{
    toExecute.push_back(command);
    return 0;
}
void Gestionnaire::printVector(){

    cout<<"To execute"<<endl;
    for (unsigned i=0; i<toExecute.size(); ++i)
        cout << ' ' << toExecute[i]->getPid()<<endl;

    cout<<"Running"<<endl;
    for (unsigned i=0; i<running.size(); ++i)
        cout << ' ' << running[i]->getPid()<<endl;
}
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
		Monitor monitor (50,95);


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
            //Rajoute des processus
            //Ajoute des processus dans running et en enleve de toExecute
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
					Job* jobToLaunch= strategie.strategieDefault(toExecute);
					for (int i=0; i<toExecute.size(); i++)
					{
						if (toExecute[i]->getPid()==jobToLaunch->getPid())
						{
							running.push_back(toExecute[i]);
							toExecute[i]->resume();
							toExecute.erase(toExecute.begin()+i);

						}
					}

				}
				
            }
            //Enleve des processus
            //Ajoute des processus dans toExecute et en enleve de running
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

					Job* jobToPause= strategie.strategieDefault(running);
					for (int i=0; i<running.size(); i++)
					{
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
			
				Job* jobToPause= strategie.strategieMemMax(running);
				cout<<"========================================================================="<<endl;
				cout<<"Attention !: Le processus "<<jobToPause->getName()<<" a été tué car il consommait trop de memoire !"<<endl;
				cout<<"========================================================================="<<endl;
				for (int i=0; i<running.size(); i++)
				{
					if (running[i]->getPid()==jobToPause->getPid())
					{
						running.erase(running.begin()+i);
					}
				}
				killed.push_back(jobToPause);
				jobToPause->killProcess();
			}
		}
    }
    return 0;
}


void Gestionnaire::launchProcess()
{
    for (unsigned i=0; i<toExecute.size(); ++i)
    {
        toExecute[i]->launch();
        toExecute[i]->pause();
    }
}
