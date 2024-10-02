# Variables
CC = gcc
CFLAGS = -L../hello -lhello

# Targets
all: my_server

my_server: server.o
	$(CC) -o my_server server.o $(CFLAGS)

server.o: server.c
	$(CC) -c server.c

clean:
	rm -f *.o my_server
