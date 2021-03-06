#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <list>
#include <iostream>
#include "job1.hpp"

using namespace std;

int main( int argc, char* argv[] ){
	// Création des Job
	Job1 job1 = Job1();
	Job1 job2 = Job1();

	// Lancement des Jobs
	job1.launch();
	job2.launch();

	// Alterner l'exécution des deux job toutes le 5s
	job2.pause();
	while(1){
		sleep(5);
		job1.pause();
		job2.resume();
		sleep(5);
		job1.resume();
		job2.pause();
	}
	return 0;
}
