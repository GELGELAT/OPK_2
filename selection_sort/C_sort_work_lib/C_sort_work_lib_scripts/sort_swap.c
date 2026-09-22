#include "sort_swap.h"
#include <string.h>

void swap_two_any(const void* a, const void*b,size_t size)
{
    void* temp = malloc(size);
    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);
    free(temp);
}