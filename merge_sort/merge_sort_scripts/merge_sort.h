#pragma once

#include <stddef.h>
#include "sort_work_lib.h"

void merge_sort(void *array, size_t amount, size_t size, int (*cmp)(const void *a, const void *b));

