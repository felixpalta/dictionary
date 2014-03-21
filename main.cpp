/*
This program takes input as text from stdin
and makes a dictionary of all the words, encountered in it.
It also counts numbers of occurrences of each word.
Available arguments:
 -all 
	- prints all entries with the numbers of their occurrences
 -top N 
	- prints top N most frequently encountered entries with the numbers of their occurrences
 -find entry1 entry2 entry3
	- searches for entries in the dictionary with the numbers of their occurrences

 */

#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

#include "Arguments.h"
using namespace  std;

// prints program manual
void print_manual(){
	cout << "manual here!" << endl;
};



int main(int argc, char* argv[])
try {
	
	Arguments args(argc,argv);	// either creates a set of arguments or throws an exception

	map<string,int> words;	// container for the dictionary

	string s;
	while (cin >> s) ++words[s];

	typedef map<string,int>::const_iterator Iter;
	switch (args.operation()){
	case Arguments::BAD: throw runtime_error("Argument parsing error"); break;
	case Arguments::PRINT_ALL:
		for (Iter i = words.begin(); i != words.end(); ++i)
			cout << i->first << ": " << i->second << endl;
		break;
	case Arguments::PRINT_TOP:
		break;
	case Arguments::FIND_WORDS:
		break;
	default:
		break;
	}	
}

catch (invalid_argument& e){
	cout << e.what() << endl;
	print_manual();
	return 1;
}
catch (runtime_error& e){
	cout << "Runtime error: ";
	cout << e.what() << endl;
	return 2;
}