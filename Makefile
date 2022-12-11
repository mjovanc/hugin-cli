CC=cc
CFLAGS=-std=c11
CFLAGS+=-W -Wall
CFLAGS+=-O0 -g -ggdb
#LDLIBS=
#LDFLAGS=

SRCS=main.c
TARGETS=main #libfoo.a libbar.a

main: build/main.o

all: $(TARGETS)