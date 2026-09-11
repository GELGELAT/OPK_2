#include "charac.h"

float* characteristics_array_numbers(float* numbers_array, int amount)
{
    float* charac_arr = malloc(sizeof(float)*7);
    for (int i =0;i<amount;i++)
    {
        charac_arr[i]=0;
        charac_arr[i]+=numbers_array[i];
    }
    return charac_arr;
}