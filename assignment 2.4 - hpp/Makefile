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
SOURCES := 

# header files in this project
HEADERS := 

# other places to look for files for this project
SEARCH  := ../w1-library

build: song.cpp
song.cpp: Makefile native.exe
	native.exe > song.cpp

native.exe: rtttl_string_converter.cpp note_printer.cpp note_player.hpp
	g++ rtttl_string_converter.cpp note_printer.cpp -o native.exe

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
