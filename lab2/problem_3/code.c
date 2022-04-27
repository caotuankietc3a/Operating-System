#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER 10
void *hello(void *tid) {
  printf("Hello from thread %d\n", (int)tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t tid[NUMBER];
  int i;
  for (int i = 0; i < NUMBER; i++) {
    int rc = pthread_create(&tid[i], NULL, hello, (void *)i);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
    pthread_join(tid[i], NULL);
  }
  pthread_exit(NULL);
  /* gcc -pthread -o code code.c */
}
