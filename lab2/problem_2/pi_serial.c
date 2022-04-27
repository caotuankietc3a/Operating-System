#include <math.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double random_number() { return (random() / ((double)RAND_MAX)) * 2 - 1; }

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("Please enter number of points!!\n");
    exit(1);
  }
  double num_of_points = (double)atoi(argv[1]);
  double points_in_circle = 0;

  srandom((unsigned)time(NULL));
  clock_t begin = clock();

  for (int i = 0; i < num_of_points; i++) {
    double x = random_number();
    double y = random_number();
    if (sqrt(x * x + y * y) <= 1) {
      ++points_in_circle;
    }
  }
  double pi = 4 * points_in_circle / num_of_points;
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Serial calculating pi: %lf\n", pi);
  printf("Serial calculating speed: %lf\n", time_spent);
  return 0;
}
