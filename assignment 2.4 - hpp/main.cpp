#include "hwlib.hpp"
#include "song.hpp"

int main( void ){	
    
   // kill the watchdog, wait for the PC console to start
   WDT->WDT_MR = WDT_MR_WDDIS;
   hwlib::wait_ms( 1000 );
   return 1;
   
}
