PROG            = initadv
CFLAGS          = -g #-Wall -Werror -O
LDFLAGS         = -g
OBJ             = fatal.o getlin.o getobj.o iactio.o icave.o iclass.o \
                  ievent.o imessa.o initadv.o iobjec.o ivocab.o \
                  putcnd.o putmes.o screen.o stat.o vocab.o savecm.o

all:            $(PROG)

clean:
		rm -f *.o $(PROG)

$(PROG):        $(OBJ)
		$(CC) $(LDFLAGS) $(OBJ) -o $@
