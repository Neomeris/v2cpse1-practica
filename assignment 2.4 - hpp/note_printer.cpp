#include "note_printer.hpp"
#include <iostream>
#define COUT std::cout

void note_printer::play( const note & n ){
	COUT << "note{ " << n.frequency << ", "  << n.duration << " }\n";
}