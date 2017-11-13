#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

int main ()
{
	const char * filename = "file.dat";
	char data[100];
	
	while(1){
		// Read every seconds
		sleep(1);
		
		// Open the file
		ifstream afile(filename);
		
		// While there's still stuff to read
		while(afile.is_open()){
			// Read one line
			afile.getline(data, 100, '\n');
			
			// If nothing more to read
			if(*data == 0){
				std::cout << "nothing more to read" << std::endl;
				
				// Close file and delete content
				afile.close();
				fclose(fopen(filename, "w"));	
			}
			else{
				// Build commands objects here
				std::cout << data << std::endl;

			}
		}
	}
}
