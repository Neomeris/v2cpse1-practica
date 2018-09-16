#include "song.hpp"
#include "hwlib.hpp"

int main( void ){	
    
   // kill the watchdog, wait for the PC console to start
   WDT->WDT_MR = WDT_MR_WDDIS;
   hwlib::wait_ms( 1000 );
   namespace target = hwlib::target;   
   auto lsp = target::pin_out( target::pins::d7 );
   auto p = note_player_gpio( lsp );
   auto s = song();
   auto np = note_printer();
   s.play(np);
   s.play(p);
   return 1;

   
}
