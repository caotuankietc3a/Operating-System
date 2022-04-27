#ifndef EX1_H
#define EX1_H
#include <stdbool.h>
void *aligned_malloc(unsigned int size, unsigned int align);
bool check_align(unsigned int align);
void *aligned_free(void *ptr);

#endif
