#include <string>
#include <iostream>
#include "Dictionary_containter.h"

class Dictionary  {
	
public:
	Dictionary(): words() {
	};
	void get_data();
	const Words_map& data() const {return words;}
private:
	Words_map words;

	typedef Words_map::const_iterator Iter;
	
	void print_all() const;
};