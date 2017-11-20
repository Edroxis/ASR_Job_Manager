#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{

}

/**
 * @brief Gestionnaire::add Add a job to the list to launch
 * @param job the job to add
 * @return
 */
int Gestionnaire::add(Job* job)
{
    toExecute.push_back(job);
    return 0;
}

/**
 * @brief Gestionnaire::add Add a command to the list to launch
 * @param command the command to add
 * @return
 */
int Gestionnaire::add(Command* command)
{
    toExecute.push_back(command);
    return 0;
}

/**
 * @brief Gestionnaire::printVector Print a vector
 */
void Gestionnaire::printVector(){

    cout<<"To execute"<<endl;
    for (unsigned i=0; i<toExecute.size(); ++i)
        cout << ' ' << toExecute[i]->getPid()<<endl;

    cout<<"Running"<<endl;
    for (unsigned i=0; i<running.size(); ++i)
        cout << ' ' << running[i]->getPid()<<endl;
}

/**
 * @brief Gestionnaire::launch Launch the monitor
 * @return
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
        //Launch the monitor
		Monitor monitor (50,95);


		while(1){
            //The action to do
            string res=monitor.ActionSystem();
            // Send the action through the output side of pipe
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
            //Read the action from the pipe
            nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
			string res= readbuffer;
            cout<<"Lu :"<<res<<endl;
            //Launch more process from the waitinq queue
            if(res=="+")
            {
                //If there're still process to launch
                if(toExecute.empty()==false)
                {
                    cout<<"Ajoute"<<endl;
                    //Add the processing in the running vector
                    running.push_back(toExecute[toExecute.size()-1]);
                    //Launch the process
                    toExecute[toExecute.size()-1]->resume();
                    //Remove it of the waiting queue
                    toExecute.pop_back();
                    printVector();
                }


            }
            //Remove process of the running queue
            else if(res=="-cpu")
            {
                if(running.empty()==false)
                {
                    cout<<"Enleve"<<endl;
                    //Add the job to the waiting queue
                    toExecute.push_back(running[running.size()-1]);
                    //Pause the process
                    running[running.size()-1]->pause();
                    //Remove the process of the running queue
                    running.pop_back();
                    printVector();
                }
            }

		}


    }
    return 0;
}

/**
 * @brief Gestionnaire::launchProcess Launch all the processes and pause them
 */
void Gestionnaire::launchProcess()
{
    for (unsigned i=0; i<toExecute.size(); ++i)
    {
        toExecute[i]->launch();
        toExecute[i]->pause();
    }
}
