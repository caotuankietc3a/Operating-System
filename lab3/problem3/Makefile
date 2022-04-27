#Makefile
all:
	make pi_mutex_lock pi_semaphore pi_ordinary

pi_mutex_lock: pi_mutex_lock.o
	gcc -o pi_mutex_lock pi_mutex_lock.o -pthread -lm

pi_mutex_lock.o: pi_mutex_lock.c
	gcc -c pi_mutex_lock.c -pthread

pi_semaphore: pi_semaphore.o
	gcc -o pi_semaphore pi_semaphore.o -pthread -lm

pi_semaphore.o: pi_semaphore.c
	gcc -c pi_semaphore.c -pthread	

pi_ordinary: pi_ordinary.o
	gcc -o pi_ordinary pi_ordinary.o -pthread -lm

pi_ordinary.o: pi_ordinary.c
	gcc -c pi_ordinary.c -pthread

clean:
	rm -f *.o pi_semaphore pi_mutex_lock pi_ordinary
