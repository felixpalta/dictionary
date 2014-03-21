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

using namespace  std;

// prints program manual
void print_manual(){
	cout << "manual here!" << endl;
};


int main(int argc, char* argv[])
try {
	
	enum Operation {
		PRINT_ALL,
		PRINT_TOP,
		FIND_WORDS,
		BAD,
	};

	map<string,int> words;	// container for the dictionary
	Operation op = BAD;
	int top_number = 0;	// number of top entries to find with -top argument
	vector<string> words_to_find;	// list of entries to find with -find argument



	switch (argc){
	case 0: throw runtime_error("argc == 0"); break;	// hardly possible
	case 1: throw invalid_argument("At least one argument needed"); break;
	case 2: 
		if (string(argv[1]) != "-all") throw invalid_argument("Wrong argument, expected -all");
		op = PRINT_ALL;
		break;
	default:
		if (string(argv[1]) == "-top" && argc == 3) {
			istringstream iss(argv[2]);
			iss >> top_number;
			if (! iss ) 
				throw invalid_argument("Expected number of top entries after -top");
			op = PRINT_TOP;
			break;
		} else if (string(argv[1]) == "-find"){
			for (int i = 2; i < argc; ++i) words_to_find.push_back(string(argv[i]));
			if (words_to_find.size() == 0) throw invalid_argument("Expected a list of entries to find");
			op = FIND_WORDS;
			break;
		}
		throw invalid_argument("Expected -top with number of entries or -find with a list of entries");
		break;
	}

	string s;
	while (cin >> s) ++words[s];

	typedef map<string,int>::const_iterator Iter;
	switch (op){
	case BAD: throw runtime_error("Argument parsing error"); break;
	case PRINT_ALL:
		for (Iter i = words.begin(); i != words.end(); ++i)
			cout << i->first << ": " << i->second << endl;
		break;
	case PRINT_TOP:
		break;
	case FIND_WORDS:
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