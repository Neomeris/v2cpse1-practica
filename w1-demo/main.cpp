#include "hwlib.hpp"
#include "note_player_gpio.hpp"
#include "fur_elise.hpp"
#include "rtttl_player.hpp"

const char * let_it_be = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6";
const char * we_rock = "we-rock:d=4,o=6,b=140:32d#.5,32d.5,32d#.5,8f#.5,32g#.5,32f#.5,32f.5,32f#.5,8a#.5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,8f#.6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,16f5,32d#5,16d5,16d#5,4f#5,16g#5,16f#5,16f5,16f#5,4a#5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,4f#6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,8a#5,8b5,8c#6,8c#6,16d#6,16c#6,16b5,";
const char * vrolijk = "ZoVrolij:d=4,o=5,b=125:8g,8c6,8c6,8c6,8c6,8g,8g,8p,8g,8a,8a,8p,8a,8e,8e,8p,8e,8f,8d,8a,8a,8g,8g,8p,8g,8c,8d,8e,8g,c6,8p,8g,8c6,8c6,8c6,8c6,8g,8g,8p,8g,8a,8a,8p,8a,8e,8e,8p,8e,8f,8d,8a,8a,8g,8g,8p,8g,8c,8d,8e,8g,c6,8p,8g,8c6,8c6,8c6,8c6,8g,8g,8p,8g,8a,8a,8p,8a,8e,8e,8p,8e,8f,8d,8a,8a,8g,8g,8p,8g,8c,8d,8e,8g,c6,8p";
const char * tocatta = "ToccataA:d=32,o=6,b=90:16d,d#.,f.,d.,d#.,f.,d.,d#.,f.,d.,16d#,16f,f#.,g#.,f.,f#.,g#.,f.,f#.,g#.,f.,16f#,16g#,a#.,b.,g#.,a#.,b.,g#.,a#.,b.,16g#,2a#,16a#,g#.,b.,f.,g#.,b.,f.,f#.,a#.,d#.,f#.,a#.,d#.,f.,g#.,d.,f.,g#.,d.,d#.,f#.,c.,d#.,16f#,16c,16c#,16f,16a#5,16c#,16f,16a#5,16c,16d#,16g#5,16c,16d#,16g#5,16a#5,16c#,16f#5,16a#5,16c#,16f#5,16g#5,16b5,16f5,16g#5,16b5,16f5,16f#5,16a#5,16d#5,16f#5,16a#5,16d#5,16f5,16g#5,16d5,16f5,16g#5,16d.5,4d#.5";
const char * tocatta2 = "ToccataA:d=32,o=5,b=100:a#.,g#.,2a#,g#,f#,f,d#.,4d.,2d#,a#.,g#.,2a#,8f,8f#,8d,2d#,8d,8f,8g#,8b,8d6,4f6,4g#.,4f.,1g";

int main( void ){	
    
   // kill the watchdog, wait for the PC console to start
   WDT->WDT_MR = WDT_MR_WDDIS;
   hwlib::wait_ms( 1000 );   
   
   namespace target = hwlib::target;   
   auto lsp = target::pin_out( target::pins::d7 );
   auto p = note_player_gpio( lsp );
   
   if(0){
      auto fe = fur_elise();
      fe.play( p );
      return 0;
   }      
   
   if(1){
      rtttl_play( p, tocatta );
	  rtttl_play( p, tocatta2 );
      return 0;
   }
}
