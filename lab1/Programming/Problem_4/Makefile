CC=gcc
CFLAG=-c -Wall

all: problem4.o
	$(CC) problem4.o -o problem4 && ./problem4 numbers.txt && rm -rf *.o problem4

problem4.o: problem4.c
	$(CC) $(CFLAG) problem4.c
