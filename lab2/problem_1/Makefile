CC=gcc
CFLAG=-c -Wall

all: complie
	./main && rm -rf main *.o

complie: main.o ex1.o
	$(CC) main.o ex1.o -o main

main.o: main.c
	$(CC) $(CFLAG) main.c

ex1.o: ex1.c
	$(CC) $(CFLAG) ex1.c
