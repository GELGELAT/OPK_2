#include "create_arrays.h"
#include <stdlib.h>
#include "rand_main.h"

float* create_rand_with_in_arr_f(int amount, float min,float max)
{
    float* arr = malloc(sizeof(float)*amount);
    for(int i =0;i<amount;i++)
    {
        arr[i] = rand_with_in_f(min,max);
    }
    return arr;
}