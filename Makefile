CC=gcc
CFLAGS=-I. -lwiringPi -Wall

example1:
	$(CC) -o example1 example1.c xmas.c $(CFLAGS)

random:
	$(CC) -o random random.c xmas.c $(CFLAGS)
	
