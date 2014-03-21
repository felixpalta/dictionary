#pragma once
#include <iostream>
#include <string>

inline void print_usage(){
	std::cout <<
		"Available arguments:\n"
		"-all : print all entries with the numbers of their occurrences\n" 
		"-find entry1 entry2 entry3 : search for entries in the dictionary with the numbers of their occurrences\n"
		"\nExample: dictionary -find Romeo Juliette < RomeoAndJuliette.txt"
		<< std:: endl;
}

inline void print_manual(){
	std::cout << 
		"This program takes input as text from stdin "
		"and makes a dictionary of all the words, encountered in it.\n"
		"It also counts numbers of occurrences of each word.\n"
		<< std::endl;
	print_usage();
};

