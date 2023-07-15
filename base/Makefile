INITADV         = ../initadv/initadv
CFLAGS          = -g -Werror -Wall -O
LDFLAGS         = -g
SRC             = advactio advcave advclass advevent advmessa advobjec advvocab

all:            data.adv

clean:
		rm -f *.adv

data.adv:       $(INITADV) $(SRC)
		$(INITADV) || rm $@

$(INITADV):
		make -C ../initadv all
