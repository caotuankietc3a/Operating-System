#Makefile
all:
	make cond_usg nosynch

cond_usg: cond_usg.o
	gcc -o cond_usg cond_usg.o -pthread

cond_usg.o: cond_usg.c
	gcc -c cond_usg.c -pthread

nosynch: nosynch.o
	gcc -o nosynch nosynch.o -pthread

nosynch.o: nosynch.c
	gcc -c nosynch.c -pthread	

clean:
	rm -f *.o nosynch cond_usg
