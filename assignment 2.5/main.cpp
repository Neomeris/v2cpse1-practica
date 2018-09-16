#include "song.hpp"
#include "hwlib.hpp"

int main( void ){	
    
   // kill the watchdog, wait for the PC console to start
   WDT->WDT_MR = WDT_MR_WDDIS;
   hwlib::wait_ms( 1000 );
   auto s = song();
   auto np = note_printer();
   s.play(np);
   return 1;

   
}
