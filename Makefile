.PHONY: all
all: main

CC=cc
CFLAGS=-std=c11
#CFLAGS+=-W -Wall
#CFLAGS+=-O0 -g -ggdb
#LDLIBS=
#LDFLAGS=

#SRCS=main.c
#TARGETS=main

#all: $(TARGETS)

main: main.o
	gcc -o $@ $^

main.o: main.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o main