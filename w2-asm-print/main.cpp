#include "hwlib.hpp"
#include "message.hpp"
#include <string>

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void uart_put_int( char x ){
	if (x == '\0'){hwlib::cout << "haha";}
   hwlib::cout << x << '\n';
}

extern "C" void print_asciz( const char * s );

extern "C" void application(){
   print_asciz( "Hello world\n" );	
}

extern "C" void add_one_to_int(const char * x);

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 500 );
   const char * s = "hehe\0";
   const char * p = s;
   add_one_to_int(p);
   hwlib::cout << p;
   //application();
}