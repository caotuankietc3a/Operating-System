#include <math.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double num_of_points;
atomic_int points_in_circle = 0;
#define num_of_threads 3

double randomNumber() {
  return ((double)random() / ((double)RAND_MAX)) * 2 - 1;
}

void *count_points(void *param) {
  double points = *(double *)param;
  for (int i = 0; i < points; i++) {
    double x = randomNumber();
    double y = randomNumber();
    if (sqrt(x * x + y * y) <= 1) {
      ++points_in_circle;
    }
  }
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("Please enter number of points!!\n");
    exit(1);
  }

  pthread_t threads[num_of_threads];
  num_of_points = (double)atoi(argv[1]);
  double points_per_thread = num_of_points / num_of_threads;
  int rest_points_per_thread = (int)num_of_points % num_of_threads;
  int rc;

  srandom((unsigned)time(NULL));
  clock_t begin = clock();

  for (int i = 0; i < num_of_threads; i++) {
    if (i == 3) {
      points_per_thread += rest_points_per_thread;
    }
    rc = pthread_create(&threads[i], NULL, count_points, &points_per_thread);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
    pthread_join(threads[i], NULL);
  }
  double pi = 4 * points_in_circle / num_of_points;
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Multi_Thread calculating pi: %lf\n", pi);
  printf("Multi_Thread calculating speed: %lf\n", time_spent);
  return time_spent / 256;
}
