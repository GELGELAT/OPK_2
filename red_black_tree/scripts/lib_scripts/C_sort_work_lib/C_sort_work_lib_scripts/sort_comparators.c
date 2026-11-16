#include "sort_comparators.h"
#include <math.h>
#include <stdio.h>
#include "sort_comparators.h"
#define EPSILON_F 0.00001
#define EPSILON_D 0.00000001
int cmp_float(void *a, void *b)
{
    float x = *( float*)a;
    float y = *( float*)b;
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
int cmp_int( void *a, void *b)
{
    int x = *( int*)a;
    int y = *( int*)b;
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
int cmp_int_inv( void *a, void *b)
{
    int x = *( int*)a;
    int y = *( int*)b;
    if (x>y)
    {
        return -1;
    }
    if (x<y)
    {
        return 1;
    }
    return 0;
}
int cmp_size_t(size_t a,size_t b)
{
    size_t x = a;
    size_t y = b;
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
int cmp_char( void *a, void *b)
{
    char x = *( char*)a;
    char y = *( char*)b;
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
int cmp_string( void *a, void *b)
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
int cmp_double( void *a, void *b)
{
    double x = *( double*)a;
    double y = *( double*)b;
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