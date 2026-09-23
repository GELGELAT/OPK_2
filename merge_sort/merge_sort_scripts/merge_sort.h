#pragma once

#include <stddef.h>
#include "sort_work_lib.h"

void merge_sort(void *array, size_t amount, size_t size, int (*cmp)(const void *a, const void *b));

void merge(void *main_arr, size_t start_pos, void *start_first_ptr, size_t amount_first, void *start_second_ptr, size_t amount_second, size_t size, int (*cmp)(const void *a, const void *b));



