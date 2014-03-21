#pragma once

#include <vector>
#include <string>


class Arguments {

public:
	typedef std::vector<std::string> entriesVector;
	enum Operation {
		PRINT_ALL,
		PRINT_TOP,
		FIND_WORDS,
		BAD,
	};
	Arguments(int argc, char* argv[]);
	Operation operation() const {return op;}
	int topEntriesNumber() const {return top_number;}
	const entriesVector& listOfEntries() const { return words_to_find;}

private:
	Operation op;
	int top_number;	// number of top entries to find with -top argument
	entriesVector words_to_find;	// list of entries to find with -find argument
};