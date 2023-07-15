PROG            = advent
CFLAGS          = -g -I../common -Werror #-Wall -O
LDFLAGS         = -g
OBJ             = act.o indobj.o dark.o freeze.o \
                  inpans.o pct.o tolower.o advent.o \
                  descr.o get.o mes.o rspeak.o yes.o \
                  chnloc.o events.o getans.o motion.o \
                  score.o conv.o fatal.o mscore.o \
                  specia.o vocab.o savecm.o trim.o

VPATH = ../common

all:            $(PROG)

clean:
		rm -f *.o $(PROG)

$(PROG):        $(OBJ)
		$(CC) $(LDFLAGS) $(OBJ) -o $@
###
