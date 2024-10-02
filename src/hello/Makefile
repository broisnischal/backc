# Variables
CC = gcc
CFLAGS = -c

# Targets
all: libhello.a

libhello.a: hello.o
	ar rcs libhello.a hello.o

hello.o: hello.c hello.h
	$(CC) $(CFLAGS) hello.c

clean:
	rm -f *.o libhello.a
