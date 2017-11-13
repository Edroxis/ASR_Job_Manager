#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

int main () {

  int pfd[2];
  int rc;

  if( pipe(pfd) < 0 ) {
    perror("pipe");
    return 1;
  }

  switch(fork()) {
  case -1: // Error
    perror("fork");
    return 1;

  case 0: { // Child
    // Close the writing end of the pipe
    close(pfd[1]);

    // Create a filename that refers to reading end of pipe
    std::ostringstream path;
    path << "/proc/self/fd/" << pfd[0];

    // Invoke the subject program. "cat" will do nicely.
    execlp("/bin/cat", "cat", path.str().c_str(), (char*)0);

    // If we got here, then something went wrong, then execlp failed
    perror("exec");
    return 1;
  }

  default: // Parent
    // Close the reading end.
    close(pfd[0]);

    // Write to the pipe. Since "cat" is on the other end, expect to
    // see "Hello, world" on your screen.
	while(1){
		std::string str = std::string();
		std::cin >> str;
		//std::cout << str;
		write(pfd[1], str.c_str(), str.size());
	}

    //if (write(pfd[1], "Hello, world\n", 13) != 13)
    //  perror("write");

    // Signal "cat" that we are done writing
    close(pfd[1]);

    // Wait for "cat" to finish its business
    if( wait(0) < 0)
      perror("wait");

    // Everything's okay
    return 0;
  }
}
