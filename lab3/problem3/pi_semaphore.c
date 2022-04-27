#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double num_of_points;
int points_in_circle = 0;
#define num_of_threads 3
static sem_t lock;

double randomNumber() {
  return ((double)random() / ((double)RAND_MAX)) * 2 - 1;
}

void *count_points(void *param) {
  double points = *(double *)param;
  for (int i = 0; i < points; i++) {
    double x = randomNumber();
    double y = randomNumber();
    sem_wait(&lock);
    if (sqrt(x * x + y * y) <= 1) {
      ++points_in_circle;
    }
    sem_post(&lock);
  }
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("Please enter number of points!!\n");
    exit(1);
  }

  pthread_t threads[num_of_threads];
  sem_init(&lock, 0, 1);
  num_of_points = (double)atoi(argv[1]);
  double points_per_thread = num_of_points / num_of_threads;
  int rest_points_per_thread = (int)num_of_points % num_of_threads;
  int rc;

  srandom((unsigned)time(NULL));
  clock_t begin = clock();

  for (int i = 0; i < num_of_threads; i++) {
    points_per_thread += i < rest_points_per_thread;
    rc = pthread_create(&threads[i], NULL, count_points, &points_per_thread);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  for (int i = 0; i < num_of_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  clock_t end = clock();
  sem_destroy(&lock);

  double pi = 4 * points_in_circle / num_of_points;
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Number of points in circle: %d\n", points_in_circle);
  printf("Multi_Thread calculating pi: %lf\n", pi);
  printf("Multi_Thread calculating speed: %lf\n", time_spent);
  return 0;
}
