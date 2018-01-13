# Behavior of the different class

## Class Command 
Allow the instanciation of a job from a shell command

### Command(const char * str) 
* \brief Constructor <br/>
* \params str the command 

### build_argv(const char * str)
* \brief Get the argument of the command <br/>
* \params str the command

### calc_nb_elements(const char * str)
* \brief Compute the number of arguments of the command <br/>
* \params str the command <br/>
* \return the number of arguments

### run()
* \brief Launch the command <br/>
* \return 0

## Class Gestionnaire
Main class of the librairy. You need to instanciate an bject, add all the jobs and finally launch the administrator

### Gestionnaire(int levelMin, int levelMax)
* \brief consrtuctor <br/>
* \params levelMin the level minimum <br/>
* \params levelMax the level maximum

### add(Job* job)
* \brief add a job <br/>
* \params job the job to add <br/>
* \return 0

### add (Command* command)
* \brief add a command <br/>
* \params command the command to add <br/>
* \return 0

### printVector()
* \brief print all the vector

### launch()
* \brief launch the manager
* \return 0

### launchProcess()
* \brief launch all of the process then pause them

## Class Job
Mother class allowing to launch code through the function run()

### Job(const char* processName)
* \brief constructor <br/>
* \param processName the process name 

### Job(Job * job1)
* \brief constructor <br/>
* \param job1 a job

### Job()
* \brief launch a job()

### Launch()
* \brief launch a job

### Pause()
* \brief pause a job

### getName
* \brief get the name oh a job <br/>
* \return 0

### resume
* \brief resume a job <br/>
* \return 0

### getPid()
* \brief get the pid of a job <br/>
* \return the pid

### killProcess()
* \brief kill a processs <br/>
* \return 0

### ~Job()
* \brief destructor

## Class Monitor
Monitor the system by checking the CPU an memory charge and determine what to do 

### Monitor(float min, float max)
* \brief create a new monitor with the max  and the min of the system charge   <br/>
* \param min the minal charge of the system <br/>
* \param max the maximal charge of the system

### GetCPUCharge()
* \brief get the percent of CPU charge which is free <br/>
* \return the percent of free CPU charge

### GetMemCharge(void)
* \brief get the percent of memory which is free <br/>
* \return the percent of free memory

### ActionSystem()
* \brief Get the action that the system has to do

## Class Strategie
Define all the strategy to adopt in order to determine what job to pause and launch

### strategieDefault(vector<Job*> running)
* \brief Default strategie <br/> 
* \param running the list of the process <br/>
* \return the job to kill/pause/launch

### strategieMemMax(vector<Job*> running)
* \brief get the process which used the most memory <br/>
* \param running the list of the process <br/>
* \return the job to kill
