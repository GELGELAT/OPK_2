#include "sort_comparators.h"
#include <math.h>
#include <stdio.h>
#define EPSILON_F 0.00001
#define EPSILON_D 0.00000001
int cmp_float(const void *a,const void *b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;
    if (fabsf(x-y)<EPSILON_F)
    {
        return 0;
    }
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
int cmp_int(const void *a,const void *b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;
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
int cmp_char(const void *a,const void *b)
{
    char x = *(const char*)a;
    char y = *(const char*)b;
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
int cmp_string(const void *a,const void *b)
{
    char* x = *( char**)a;
    char* y = *( char**)b;
    int i =0;
    int x_len=0;
    int y_len=0;
    while (x[i] != '\0')
    {
        x_len++;
        i++;
    }
    i =0;
    while (y[i] != '\0')
    {
        y_len++;
        i++;
    }
    if (x_len<y_len)
    {
        return -1;
    }
    if (x_len>y_len)
    {
        return 1;
    }
    return 0;
}
int cmp_double(const void *a,const void *b)
{
    double x = *(const double*)a;
    double y = *(const double*)b;
    if (fabs(x-y)<EPSILON_D)
    {
        return 0;
    }
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