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
song.cpp: Makefile convert_rtttl_string.exe rtttl_string_file.txt
	convert_rtttl_string.exe "rtttl_string_file.txt" > song.cpp


convert_rtttl_string.exe: rtttl_string_converter.cpp note_printer.cpp
	g++ rtttl_string_converter.cpp note_printer.cpp -o convert_rtttl_string.exe

# source files in this project (main.cpp is automatically assumed)
SOURCES := note_printer.cpp song.cpp note_player_gpio.cpp

# header files in this project
HEADERS := note_printer.hpp note_player.hpp song.hpp note_player_gpio.hpp

# other places to look for files for this project
SEARCH  := ../w1-library

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
