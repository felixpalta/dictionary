#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <vector>

#include "Arguments.h"
#include "applyOperation.h"

using namespace std;

void applyOperation(const Words_map& words, const Arguments& args){

	typedef Words_map::const_iterator Iter;

	switch (args.operation()){
	case Arguments::BAD: 
		throw runtime_error("Argument parsing error"); return;

	case Arguments::PRINT_ALL:
		for (Iter i = words.begin(); i != words.end(); ++i)
			cout << i->first << ": " << i->second << endl;
		return;

	case Arguments::FIND_WORDS:
		for (Arguments::entriesVector::const_iterator vectIter = args.listOfEntries().begin(); vectIter != args.listOfEntries().end(); ++vectIter){
			
			Iter wordIter = words.find(*vectIter);	// O(log(N))
			if (wordIter == words.end()) {	// entry not found
				cout << *vectIter << ": " << "0" << endl;
				continue;
			}
			cout << wordIter->first << ": " << wordIter->second << endl;
		}
		return;
	default:
		return;
	}	
}