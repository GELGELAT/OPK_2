#pragma once

#include <stddef.h>
#include "sort_swap.h"

enum Mode 
{
    SHELL,
    HIBBARD,
    SEDJVIK,
    GEOMETRIC
};
extern int current_mode;

void shell_sort(int work_mode, void *array, size_t size, size_t type_size, int (*cmp)(const void *a, const void *b));
