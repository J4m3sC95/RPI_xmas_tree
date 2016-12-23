CC=gcc
CFLAGS=-I. -lwiringPi -Wall
DEP=xmas

TARGETS=example1 random random_indiv random_pair fade

all: $(TARGETS)

$(TARGETS): %: %.c $(DEP).o
	$(CC) -o $@ $< $(DEP).o $(CFLAGS)

$(DEP): $(DEP).c $(DEP).h
	$(CC) -c -o $@.o $< $(CFLAGS)

clean:
	rm -f $(TARGETS) $(DEP).o