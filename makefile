# pegs Makefile for djgpp

DEST=peg

CC=gcc
CXX=gcc
CXXFLAGS=-g
CFLAGS=

##########################
FLAGS=$(CXXFLAGS)
DFILE=mkdpnd
EXT=cpp
DEPEND=-MM

LIB=-lgpp
#LIB=

HDR=	g.hpp	\
		game.hpp	\
		board.hpp	\
		hole.hpp	\
		list.hpp

SRC=	main.$(EXT)	\
		game.$(EXT)	\
		board.$(EXT)	\
		hole.$(EXT)	\
		list.$(EXT)

OBJS=	main.o	\
		game.o	\
		board.o	\
		hole.o	\
		list.o

##########################

all:	$(DEST).exe $(DFILE)

$(DEST).exe:	$(OBJS)
	$(CC) $(FLAGS) -o $(DEST) $(OBJS) $(LIB)
	coff2exe $(DEST)
	del $(DEST)

$(OBJS):	$(DFILE) Makefile

%.o:	%.$(EXT) $(DFILE) Makefile
	$(CC) $(FLAGS) -c $<

$(DFILE):	Makefile
	$(CC) $(DEPEND) $(SRC) > $(DFILE)

depend:
	$(CC) $(DEPEND) $(SRC) > $(DFILE)

clean:
	del *.o $(DEST).exe core

include $(DFILE)
