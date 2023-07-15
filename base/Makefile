INITADV         = ../initadv/initadv
CFLAGS          = -g -Werror -Wall -O
LDFLAGS         = -g
SRC             = advactio advcave advclass advevent advmessa advobjec advvocab

DESTDIR         = /usr/local/share/advent

all:            data.adv

clean:
		rm -f *.adv

install:        $(DESTDIR) $(DESTDIR)/data.adv $(DESTDIR)/text.adv $(DESTDIR)/common.adv

$(DESTDIR):
		install -d $@

$(DESTDIR)/data.adv: data.adv
		install -c -m 444 $< $@

$(DESTDIR)/text.adv: text.adv
		install -c -m 444 $< $@

$(DESTDIR)/common.adv: common.adv
		install -c -m 444 $< $@

data.adv text.adv common.adv: $(INITADV) $(SRC)
		$(INITADV) || rm $@

$(INITADV):
		make -C ../initadv all
