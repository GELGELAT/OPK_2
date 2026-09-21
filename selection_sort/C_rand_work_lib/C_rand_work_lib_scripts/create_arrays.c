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
double* rand_arr_create_with_in_d(int amount, float min,float max)
{
    double* arr = malloc(sizeof(double)*amount);
    for(int i =0;i<amount;i++)
    {
        arr[i] = rand_with_in_d(min,max);
    }
    return arr;
}
int* rand_arr_create_with_in_int(int amount, int min,int max)
{
    int* arr = malloc(sizeof(int)*amount);
    for(int i =0;i<amount;i++)
    {
        arr[i] = rand_with_in_int(min,max);
    }
    return arr;
}
char* rand_arr_create_with_in_char(int amount, char min,char max)
{
    char* arr = malloc(sizeof(char)*(amount+1));
    for(int i =0;i<amount;i++)
    {
        arr[i] = rand_with_in_char(min,max);
    }
    arr[amount+1]='\0';
    return arr;
}
char** rand_arr_create_with_in_string(int amount,int min_len,int max_len, char min,char max)
{
    char** arr = malloc(sizeof(char*)*amount);
    for(int i =0;i<amount;i++)
    {
        int rand_len = rand_with_in_int(min_len,max_len);
        char* rand_str = rand_arr_create_with_in_char(rand_len,min,max);
        arr[i]=rand_str;
    }
    return arr;
}