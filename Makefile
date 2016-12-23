CC=gcc
CFLAGS=-I. -lwiringPi -Wall

TARGET1=example1
TARGET2=random
TARGET3=random_indiv
TARGET4=random_pair
TARGET5=fade

all:
	$(CC) -o $(TARGET1) $(TARGET1).c xmas.c $(CFLAGS)
	$(CC) -o $(TARGET2) $(TARGET2).c xmas.c $(CFLAGS)
	$(CC) -o $(TARGET3) $(TARGET3).c xmas.c $(CFLAGS)
	$(CC) -o $(TARGET4) $(TARGET4).c xmas.c $(CFLAGS)
	$(CC) -o $(TARGET5) $(TARGET5).c xmas.c $(CFLAGS)

clean:
	rm -f $(TARGET1)
	rm -f $(TARGET2)
	rm -f $(TARGET3)
	rm -f $(TARGET4)
	rm -f $(TARGET5)