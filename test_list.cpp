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

	mylist.push_back("hello");
	mylist.push_back("world");
	mylist.push_back("!");

	std::list<string>::const_iterator
        	lit (mylist.begin()),
        	lend(mylist.end());
    	for(;lit!=lend;++lit) std::cout << *lit << '\n';
    	std::cout << std::endl;

	return 0;
}
