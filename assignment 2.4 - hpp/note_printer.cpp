#include "note_printer.hpp"
#ifdef BMPTK_TARGET
   #include "hwlib.hpp"
   #define COUT hwlib::cout
#else
   #include <iostream>
   #define HWLIB_TRACE std::cout << "\n" << std::flush
   #define COUT std::cout
#endif

void note_printer::play( const note & n ){
	COUT << "note{ " << n.frequency << ", "  << n.duration << " }\n";
}