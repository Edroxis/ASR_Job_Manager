#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <fstream>

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
	signal(SIGUSR1, sigHandler);
	
	FILE* f = fopen("/tmp/lmaj/gestionnaire.pid", "w");
	char pid[5];

	sprintf(pid, "%d", getpid());
	fputs(pid, f);
	fclose(f);
		
	while(1);
	
	return 0;
}
