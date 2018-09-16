#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

build: song.cpp
song.cpp: convert_rtttl_string.exe
	convert_rtttl_string.exe Toccata:d=32,o=6,b=90:16d,d#.,f.,d.,d#.,f.,d.,d#.,f.,d.,16d#,16f,f#.,g#.,f.,f#.,g#.,f.,f#.,g#.,f.,16f#,16g#,a#.,b.,g#.,a#.,b.,g#.,a#.,b.,16g#,2a#,16a#,g#.,b.,f.,g#.,b.,f.,f#.,a#.,d#.,f#.,a#.,d#.,f.,g#.,d.,f.,g#.,d.,d#.,f#.,c.,d#.,16f#,16c,16c#,16f,16a#5,16c#,16f,16a#5,16c,16d#,16g#5,16c,16d#,16g#5,16a#5,16c#,16f#5,16a#5,16c#,16f#5,16g#5,16b5,16f5,16g#5,16b5,16f5,16f#5,16a#5,16d#5,16f#5,16a#5,16d#5,16f5,16g#5,16d5,16f5,16g#5,16d.5,4d#.5 > song.cpp


convert_rtttl_string.exe: rtttl_string_converter.cpp note_printer.o
	g++ rtttl_string_converter.cpp -o convert_rtttl_string.exe
	
note_printer.o: note_printer.cpp ../w1-library/note_player.hpp

# source files in this project (main.cpp is automatically assumed)
SOURCES := note_printer.cpp song.cpp

# header files in this project
HEADERS := note_printer.hpp song.hpp

# other places to look for files for this project
SEARCH  := ../w1-library

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
