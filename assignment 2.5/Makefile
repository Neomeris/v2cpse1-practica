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
	convert_rtttl_string.exe > song.cpp

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
