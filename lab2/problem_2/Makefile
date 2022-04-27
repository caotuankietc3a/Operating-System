cmd=gcc -c -Wall
all: pi_serial.o pi_multi_thread.o
	gcc -pthread pi_serial.o -o pi_serial -lm && ./pi_serial 100000
	gcc -pthread pi_multi_thread.o -o pi_multi_thread -lm && ./pi_multi_thread 100000
	rm -rf pi_serial pi_multi_thread *.o

pi_serial.o: pi_serial.c
	$(cmd) pi_serial.c

pi_multi_thread.o: pi_multi_thread.c
	$(cmd) pi_multi_thread.c

clean: 
	rm -rf pi_serial pi_multi_thread *.o
