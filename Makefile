BINARY=Hugin
CODEDIRS=.
INCDIRS=.

CC=gcc
OPT=-00
DEPFLAGS=-MP -MD
CFLAGS=-std=c11 -Wall -Wextra -g $(foreach D, $(INCDIRS), -I$(D)) $(OPT) $(DEPFLAGS)

CFILES=$(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c, %.o, $(CFILES))
DEPFILES=$(patsubst %.c, %.d, $(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
		$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)