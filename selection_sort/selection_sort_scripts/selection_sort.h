#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include <stddef.h>
#include "sort_work_lib.h"

void selection_sort(void *array, size_t amount, size_t size, int (*cmp)(const void *a, const void *b));
#endif

