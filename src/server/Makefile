# Variables
CC = gcc
CFLAGS = -Wall -Wextra -I../hello
LDFLAGS = -L../hello -lhello

SRCS = server.c router.c response.c
OBJS = $(SRCS:.c=.o)
TARGET = my_server

# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
