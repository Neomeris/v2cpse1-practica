#include <iostream>
#define COUT std::cout

using namespace std;

bool is_digit( char c ){ return ( c >= '0' ) && ( c <= '9' ); }
bool is_lowercase( char c ){ return ( c >= 'a' ) && ( c <= 'z' ); }
int frequencies[] = { 440, 494, 523, 587, 659, 698, 784 };

void rtttl_convert_string( const char *s ){
   int def_duration = 4, def_octave = 6, value;
   int duration, octave, frequency;
   int state = 0;
   char def;
   bool dot;
   COUT << "#include \"note_printer.hpp\"\nclass song{\n\tpublic:\n\tvoid play(note_player & p) {\n";
   for( const char * p = s; state >= 0; p++ ){
      const char c = *p;
      switch(state ){
             
         // title 
         case 0:
            if( c == ':' ){
               state = 1;
            } else {
               //COUT << c;
            } 
            break;
               
          // defaults  
          case 1:
            if( c == ':' ){
               state = 3;
            } if( is_lowercase( c )){
               def = c;
               value = 0;
               state = 2;
            } else {
               //HWLIB_TRACE << "c=[" << c << "]";
            } 
            break;   

         // defaults, letter stored in def
         case 2:
            if( c == '=' ){
               // ignore the =
            } else if( is_digit( c )){
               value = ( 10 * value ) + ( c - '0' );
            } else if(( c == ':' ) || ( c == ',' )) {
               if( def == 'o'){
                  def_octave = value;
               } else if( def == 'd' ){
                  def_duration = value;
               } else if( def == 'b' ){
                  // ignore
               } else {
                  //HWLIB_TRACE << "def=[" << def << "]";
               }   
               state = ( c == ':' ) ? 3 : 1;
            } else {
               //HWLIB_TRACE << "c=[" << c << "]";
            }
            break;
            
         // note start, set defaults
         case 3:  
            duration = def_duration;
            octave = def_octave;
            state = 4;
            dot = 0;
            // fallthrough!!
               
         // duration 1  
         case 4:   
            if( c == '\0' ){
               state = -1;
               break;
            } else if( is_digit( c )){
               duration = c -'0';
               state = 5;
               break;
            }            
            // fallthrough!
            
         // duration 2 
         case 5:   
            if( is_digit( c )){
               duration = ( duration * 10 ) + ( c -'0' );
               state = 6;
               break;
            }            
            // fallthrough!
               
         // note letter   
         case 6:   
            if( is_lowercase( c )){
               if( c == 'p' ){
                   frequency = 0;
               } else {
                  frequency = frequencies[ c - 'a' ]; 
               }   
            } else {
               //HWLIB_TRACE << "c=[" << c << "]";
            }   
            state = 7;
            break;
               
         // optional #   
         case 7:   
            if( c == '#' ){
               frequency = 10595 * frequency / 10000;
               state = 8;
               break;
            }
            // fallthrough!

         // optional .
         case 8:
            if( c == '.' ){
               dot = 1;
               state = 9;
               break;
            }            
            // fallthrough!

         case 9:
            if( is_digit( c )){
               octave = c - '0';
               state = 10;
               break;
            }        
            // fallthrough!
               
         case 10:   
            if( ( c == ',' ) || ( c == '\0') ){
               while( octave > 5 ){ --octave; frequency *= 2; }
               duration = 2'000'000 / duration;
               if( dot ){
                  duration = 3 * duration / 2;
               }
			   
				//change this pls
               //lsp.play( note{ frequency, duration } );
			   COUT << "\tp.play(note{ " << frequency << ", " << duration << " } );\n";
			   
               // 2017-09-27 correction: 3, not 4
               state = 3;
            } else {
               //HWLIB_TRACE << "c=[" << c << "]";
            }
            if( c == '\0' ){
               state = -1;
            }
            break;            
      }
   }
   COUT << "\t}\n};";
   //HWLIB_TRACE << "done";
   //HWLIB_TRACE;
}   

int main( void ){
	const char * tocatta = "Toccata:d=32,o=6,b=90:16d,d#.,f.,d.,d#.,f.,d.,d#.,f.,d.,16d#,16f,f#.,g#.,f.,f#.,g#.,f.,f#.,g#.,f.,16f#,16g#,a#.,b.,g#.,a#.,b.,g#.,a#.,b.,16g#,2a#,16a#,g#.,b.,f.,g#.,b.,f.,f#.,a#.,d#.,f#.,a#.,d#.,f.,g#.,d.,f.,g#.,d.,d#.,f#.,c.,d#.,16f#,16c,16c#,16f,16a#5,16c#,16f,16a#5,16c,16d#,16g#5,16c,16d#,16g#5,16a#5,16c#,16f#5,16a#5,16c#,16f#5,16g#5,16b5,16f5,16g#5,16b5,16f5,16f#5,16a#5,16d#5,16f#5,16a#5,16d#5,16f5,16g#5,16d5,16f5,16g#5,16d.5,4d#.5";
   rtttl_convert_string(tocatta);
}