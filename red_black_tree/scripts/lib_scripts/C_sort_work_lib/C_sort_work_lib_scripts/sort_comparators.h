#ifndef SORT_COMPARATORS_H
#define SORT_COMPARATORS_H

#include <stddef.h>
int cmp_float( void *a,  void *b);

int cmp_int( void *a,  void *b);

int cmp_size_t(size_t a, size_t b);

int cmp_char( void *a,  void *b);

int cmp_string( void *a,  void *b);

int cmp_double( void *a,  void *b);
int cmp_int_inv( void *a,  void *b);

#endif

