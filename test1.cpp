#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<signal.h>
#include <list>

using namespace std;

int main( int argc, char* argv[] ){
	string mystr = "hello\n";

	cout << mystr;

	std::list<string> mylist;

	mylist.push_back("hello");
	mylist.push_back("world");
	mylist.push_back("!");

	std::list<int>::const_iterator list_begin(list.begin());


	return 0;
}
