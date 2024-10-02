# Variables
SUBDIRS = src/hello src/server

# Targets
.PHONY: all clean

all:
	$(MAKE) -C src/hello
	$(MAKE) -C src/server

clean:
	$(MAKE) -C src/hello clean
	$(MAKE) -C src/server clean
