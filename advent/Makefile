PROG            = advent
DESTDIR         = /usr/local/bin
VPATH           = ../common
OBJ             = act.o indobj.o dark.o freeze.o inpans.o pct.o advent.o \
                  descr.o get.o mes.o rspeak.o yes.o chnloc.o events.o \
                  getans.o motion.o score.o conv.o fatal.o mscore.o specia.o \
                  vocab.o savecm.o trim.o unicode.o
REVCOUNT        = $(shell git rev-list HEAD --count)
COMMITHASH      = $(shell git log -1 --format=%h)

CFLAGS          = -g -I../common -Werror -Wall -O -DGAME_VERSION='"3.0.$(REVCOUNT).$(COMMITHASH)"'
LDFLAGS         = -g


all:            $(PROG)

clean:
		rm -f *.o $(PROG)

install:        $(DESTDIR)/$(PROG)

$(DESTDIR)/$(PROG): $(PROG)
		install -c -m 555 $< $@

$(PROG):        $(OBJ)
		$(CC) $(LDFLAGS) $(OBJ) -o $@
###
act.o: act.c ../common/advexter.h
advent.o: advent.c ../common/advexter.h
chnloc.o: chnloc.c ../common/advexter.h
conv.o: conv.c ../common/advexter.h
dark.o: dark.c ../common/advexter.h
descr.o: descr.c ../common/advexter.h
events.o: events.c ../common/advexter.h
freeze.o: freeze.c ../common/advexter.h
get.o: get.c ../common/advexter.h
getans.o: getans.c ../common/advexter.h
indobj.o: indobj.c ../common/advexter.h
inpans.o: inpans.c ../common/advexter.h
mes.o: mes.c ../common/advexter.h
motion.o: motion.c ../common/advexter.h
mscore.o: mscore.c ../common/advexter.h
pct.o: pct.c
rspeak.o: rspeak.c ../common/advexter.h
score.o: score.c ../common/advexter.h
specia.o: specia.c ../common/advexter.h
tolower.o: tolower.c ../common/advexter.h
trim.o: trim.c ../common/advexter.h
yes.o: yes.c ../common/advexter.h
fatal.o: ../common/fatal.c ../common/advexter.h
savecm.o: ../common/savecm.c ../common/advexter.h
vocab.o: ../common/vocab.c ../common/advexter.h
