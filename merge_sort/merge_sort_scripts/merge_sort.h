#pragma once

#include <stddef.h>
#include "sort_work_lib.h"

void merge_sort(void *array, size_t amount, size_t size, int (*cmp)(const void *a, const void *b));

void merge(void *start_first_ptr, void *last_first_ptr, void *last_second_pos, size_t size, int (*cmp)(const void *a, const void *b));
