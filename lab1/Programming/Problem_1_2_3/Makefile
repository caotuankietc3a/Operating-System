vpath %.c factorial:readline
vpath %.h factorial:readline

cmd=gcc -c -Wall
all: main.o readline.o factorial.o
	gcc main.o readline.o factorial.o -o myfactorial && ./myfactorial

main.o: main.c
	$(cmd) main.c

readline.o: readline.c readline.h
	$(cmd) readline/readline.c

factorial.o: factorial.c factorial.h
	$(cmd) factorial/factorial.c

clean: 
	rm -rf myfactorial *.o
