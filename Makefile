SUBDIR          = initadv advent

all:
		for d in $(SUBDIR); do $(MAKE) -C $$d all; done

clean:
		for d in $(SUBDIR); do $(MAKE) -C $$d clean; done