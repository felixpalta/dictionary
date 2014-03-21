#include <iostream>
#include <sstream>
#include "Arguments.h"

using namespace std;
Arguments::Arguments(int argc, char* argv[])
	:op(BAD),top_number(0),words_to_find()
{
	switch (argc){
	case 0: throw runtime_error("argc == 0"); break;	// hardly possible
	case 1: throw invalid_argument("At least one argument needed"); break;
	case 2: 
		if (string(argv[1]) != "-all") throw invalid_argument("Wrong argument, expected -all");
		op = PRINT_ALL;
		break;
	default:
		if (string(argv[1]) == "-find"){
			for (int i = 2; i < argc; ++i) words_to_find.push_back(string(argv[i]));
			if (words_to_find.size() == 0) throw invalid_argument("Expected a list of entries to find");
			op = FIND_WORDS;
			break;
		}
		throw invalid_argument("Expected -top with number of entries or -find with a list of entries");
		break;
	}
}