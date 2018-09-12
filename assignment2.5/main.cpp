#include "rtttl_string_converter.hpp"
#include "note_printer.hpp"

const char * let_it_be = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6";
const char * tocatta = "Toccata:d=32,o=6,b=90:16d,d#.,f.,d.,d#.,f.,d.,d#.,f.,d.,16d#,16f,f#.,g#.,f.,f#.,g#.,f.,f#.,g#.,f.,16f#,16g#,a#.,b.,g#.,a#.,b.,g#.,a#.,b.,16g#,2a#,16a#,g#.,b.,f.,g#.,b.,f.,f#.,a#.,d#.,f#.,a#.,d#.,f.,g#.,d.,f.,g#.,d.,d#.,f#.,c.,d#.,16f#,16c,16c#,16f,16a#5,16c#,16f,16a#5,16c,16d#,16g#5,16c,16d#,16g#5,16a#5,16c#,16f#5,16a#5,16c#,16f#5,16g#5,16b5,16f5,16g#5,16b5,16f5,16f#5,16a#5,16d#5,16f#5,16a#5,16d#5,16f5,16g#5,16d5,16f5,16g#5,16d.5,4d#.5";

int main( void ){	
    
   // kill the watchdog, wait for the PC console to start

   //auto p = note_player_gpio( lsp );
   auto kla = note_printer();
   
   
   
   if(1){
      rtttl_convert_string( tocatta );
      return 0;
   }
}
