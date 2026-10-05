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
void shell_sort(void *array, size_t amount, size_t size, int (*cmp)(const void *a, const void *b));
