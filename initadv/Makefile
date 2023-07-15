PROG            = initadv
CFLAGS          = -g -Werror #-Wall -O
LDFLAGS         = -g
OBJ             = fatal.o getlin.o getobj.o iactio.o icave.o iclass.o \
                  ievent.o imessa.o initadv.o iobjec.o ivocab.o \
                  putcnd.o putmes.o screen.o stat.o vocab.o savecm.o
VPATH = ../common

all:            $(PROG)

clean:
		rm -f *.o $(PROG)

$(PROG):        $(OBJ)
		$(CC) $(LDFLAGS) $(OBJ) -o $@
###
fatal.o: ../common/fatal.c adv_ext.h ../common/advexter.h
getlin.o: getlin.c adv_ext.h ../common/advexter.h
getobj.o: getobj.c adv_ext.h ../common/advexter.h
iactio.o: iactio.c adv_ext.h ../common/advexter.h
icave.o: icave.c adv_ext.h ../common/advexter.h
iclass.o: iclass.c adv_ext.h ../common/advexter.h
ievent.o: ievent.c adv_ext.h ../common/advexter.h
imessa.o: imessa.c adv_ext.h ../common/advexter.h
initadv.o: initadv.c adv_ext.h ../common/advexter.h
iobjec.o: iobjec.c adv_ext.h ../common/advexter.h
ivocab.o: ivocab.c adv_ext.h ../common/advexter.h
putcnd.o: putcnd.c adv_ext.h ../common/advexter.h
putmes.o: putmes.c adv_ext.h ../common/advexter.h
screen.o: screen.c adv_ext.h ../common/advexter.h
stat.o: stat.c adv_ext.h ../common/advexter.h
savecm.o: ../common/savecm.c ../common/advexter.h
vocab.o: ../common/vocab.c ../common/advexter.h
