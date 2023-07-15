SUBDIR          = initadv advent base

all:
		for d in $(SUBDIR); do $(MAKE) -C $$d all; done

install:
		for d in $(SUBDIR); do $(MAKE) -C $$d install; done

clean:
		for d in $(SUBDIR); do $(MAKE) -C $$d clean; done
