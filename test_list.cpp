#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <signal.h>
#include <list>
#include <iostream>

using namespace std;

int main( int argc, char* argv[] ){
	std::list<string> mylist;

	// Add elements to list
	mylist.push_back("hello");
	mylist.push_back("world");
	mylist.push_back("!");

	// Init Iterators
	std::list<string>::const_iterator
        	lit (mylist.begin()),
        	lend(mylist.end());
    	// Go accross the list
	for(;lit!=lend;++lit) std::cout << *lit << '\n';
    	std::cout << std::endl;

	return 0;
}
