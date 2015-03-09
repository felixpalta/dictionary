#include "Dictionary.h"

using namespace std;

void Dictionary::get_data() {
	std::string s;
	while (std::cin >> s) ++words[s];


}

void Dictionary::print_all() const {
	for (Iter i = words.begin(); i != words.end(); ++i)
		cout << i->first << ": " << i->second << endl;
}
