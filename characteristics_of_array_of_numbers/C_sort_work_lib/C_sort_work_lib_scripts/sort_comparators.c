#include "sort_comparators.h"

int cmp_float(const void *a,const void *b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;
    if (x<y)
    {
        return -1;
    }
    if (x>y)
    {
        return 1;
    }
    return 0;
    
}