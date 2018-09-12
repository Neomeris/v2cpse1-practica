#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := rtttl_player.cpp note_printer.cpp

# header files in this project
HEADERS := note.hpp rtttl_player.hpp note_printer.hpp note_player.hpp

# other places to look for files for this project
SEARCH  := 

build: native.exe

native.exe: main.cpp rtttl_player.cpp note_printer.cpp
	g++ -std=c++17 rtttl_player.cpp main.cpp note_printer.cpp -o native.exe

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native
