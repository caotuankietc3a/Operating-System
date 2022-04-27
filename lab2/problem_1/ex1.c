#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool check_align(unsigned int align) {
  if (align <= 0)
    return false;
  bool flag = true;
  while (align != 1 && flag) {
    if (align % 2 != 0)
      flag = false;
    align /= 2;
  }
  return flag;
}

void *aligned_malloc(unsigned int size, unsigned int align) {
  if (!check_align(align))
    return NULL;
  size_t sizeVoid = sizeof(void *);
  void *ptr, *p = malloc(size + (size_t)align + sizeVoid);
  if (p == NULL || size == 0) {
    return NULL;
  }

  size_t addr = ((size_t)p + (size_t)align + sizeVoid) & ~((size_t)align - 1);
  ptr = (void *)(addr);

  *((size_t *)ptr - sizeVoid) = (size_t)p;

  return ptr;
}

void *aligned_free(void *ptr) {
  free((void *)*((size_t *)ptr - 1));
  return NULL;
}
