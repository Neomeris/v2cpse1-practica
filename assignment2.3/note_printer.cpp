#include "note_printer.hpp"
#include <iostream>
#define COUT std::cout

void note_printer::play( const note & n ){
	COUT << n.frequency << "\n";
}

void note_printer::play(const char& c){
	COUT << c;
}