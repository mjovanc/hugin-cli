all: main

CC=cc
COMPILER = gcc
CFLAGS=-std=c11
#CFLAGS+=-W -Wall
#CFLAGS+=-O0 -g -ggdb
#LDLIBS=
#LDFLAGS=

CFILES=main.c
OBJECTS=main.o

BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
		$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)