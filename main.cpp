/*
This program takes input as text from stdin
and makes a dictionary of all the words, encountered in it.
It also counts numbers of occurrences of each word.
Available arguments:
 -all 
	- prints all entries with the numbers of their occurrences

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
#include "applyOperation.h"
#include "Dictionary.h"
#include "print_manual.h"
using namespace  std;

int main(int argc, char* argv[])
try {
	
	Arguments args(argc,argv);	// either creates a set of arguments or throws an exception

	Dictionary words;	// container for the dictionary

	words.get_data();	// parses input for text

	applyOperation(words.data(),args);	// uses -find or -all options on the dictionary
	
}

catch (invalid_argument& e){
	cout << e.what() << endl;
	return 1;
}
catch (runtime_error& e){
	cout << "Runtime error: ";
	cout << e.what() << endl;
	return 2;
}

