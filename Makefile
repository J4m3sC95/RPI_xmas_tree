CC=gcc
CFLAGS=-I. -lwiringPi -Wall

all:
	$(CC) -o example1 example1.c xmas.c $(CFLAGS)
	$(CC) -o random random.c xmas.c $(CFLAGS)
	$(CC) -o random_indiv random_indiv.c xmas.c $(CFLAGS)
	$(CC) -o random_pair random_pair.c xmas.c $(CFLAGS)

clean:
	rm -f example1
	rm -f random
	rm -f random_indiv
	rm -f random_pair