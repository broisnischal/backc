# Variables
CC = gcc
CFLAGS = -L../hello -lhello

# Targets
all: my_server

my_server: server.o router.o
	$(CC) -o my_server server.o router.o $(CFLAGS)

server.o: server.c router.h
	$(CC) -c server.c

router.o: router.c router.h
	$(CC) -c router.c

clean:
	rm -f *.o my_server
