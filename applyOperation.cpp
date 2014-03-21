#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <vector>

#include "Arguments.h"
#include "applyOperation.h"

using namespace std;

void applyOperation(const Dictionary& words, Arguments::Operation op){
	typedef Dictionary::const_iterator Iter;
	switch (op){
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