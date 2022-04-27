#include "ex1.h"
#include <stddef.h>
#include <stdio.h>
int main() {
  void *p = aligned_malloc(16, 64);
  printf("%p\n", p);
  aligned_free(p);
}
