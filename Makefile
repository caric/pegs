# Makefile for g++

DEST=pegs

CC=gcc
CXX=g++
#CXXFLAGS=-I/progra~1/dosapps/djgpp/include/stl
CXXFLAGS=-g
CFLAGS=

##########################
FLAGS=$(CXXFLAGS)
COMP=$(CXX)
DFILE=.makedepend
MKFILE=Makefile
EXT=cpp
DEPEND=-MM
LINKFLAGS=

.SUFFIXES:	.$(EXT)

#LIB=-lgpp -lstdcx
#LIB=-lcurses
LIB=

HDR=	g.hpp	\
	game.hpp	\
	board.hpp	\
	hole.hpp

SRC=	main.$(EXT)	\
	game.$(EXT)	\
	board.$(EXT)	\
	hole.$(EXT)

OBJS=	main.o	\
	game.o	\
	board.o	\
	hole.o

##########################

all:	$(DEST)
	@echo done.

$(DEST):	$(OBJS)
	$(COMP) $(LINKFLAGS) -o $(DEST) $(OBJS) $(LIB)

%.o:	%.$(EXT) $(MKFILE) $(DFILE)
	$(COMP) $(FLAGS) -c $<

$(DFILE):	$(MKFILE)
	$(COMP) $(DEPEND) $(FLAGS) $(SRC) > $(DFILE)
	make

depend:
	$(COMP) $(DEPEND) $(FLAGS) $(SRC) > $(DFILE)

clean:
	rm -f *.o 
	rm -f $(DEST)
	rm -f $(DFILE)

include $(DFILE)
