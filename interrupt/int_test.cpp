#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <fstream>
#include <cstdlib>

using namespace std;

const char * trsmt_fn = "/tmp/lmaj/transmit.bar";

void sigHandler(int n){
	char data[100];

	// Open the file
        ifstream trsmt_file(trsmt_fn);

	// While there's still stuff to read
	while(trsmt_file.is_open()){
		// Read one line
		trsmt_file.getline(data, 100, '\n');
		// If nothing more to read
		if(*data == 0){
			//std::cout << "nothing more to read" << std::endl;

			// Close file and delete content
			trsmt_file.close();
			fclose(fopen(trsmt_fn, "w"));
		}
		else{
			// Build commands objects here
			std::cout << data << std::endl;
			// Add command to Array
		}
	}
}

int main( int argc, char* argv[] ){
	// Execute sigHandler when SIGUSR1 is received
	signal(SIGUSR1, sigHandler);

	// Create dir lmaj
	system("mkdir /tmp/lmaj");

	// Create file and write PID of current prgm in it
	FILE* f = fopen("/tmp/lmaj/gestionnaire.pid", "w");
	char pid[5];
	sprintf(pid, "%d", getpid());
	fputs(pid, f);
	fclose(f);

	// Infinite loop (waiting for interrupts)
	while(1);

	return 0;
}
