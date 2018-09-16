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
song.cpp: native.exe
	native.exe > song.cpp

native.exe: rtttl_string_converter.cpp note_printer.cpp
	gcc rtttl_string_converter.cpp note_printer.cpp -o native.exe

# source files in this project (main.cpp is automatically assumed)
SOURCES := note_printer.cpp song.cpp

# header files in this project
HEADERS := note_printer.hpp note_player.hpp song.hpp

# other places to look for files for this project
SEARCH  := ../w1-library

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
