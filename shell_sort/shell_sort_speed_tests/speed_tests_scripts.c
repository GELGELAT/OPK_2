#include "shell_sort.h"
#include "speed_tests_scripts.h"
#include "create_arrays.h"
#include "sort_comparators.h"
#include<stdio.h>
#include <assert.h>
//double TIME = (double)(end.QuadPart - start.QuadPart) / (double)frequency.QuadPart;
LARGE_INTEGER frequency, start, end;
void tests(void)
{
    QueryPerformanceFrequency(&frequency);
    int size_arr[] = {100, 500, 1000, 2500, 5000, 10000, 50000};
    int amount_tests=100;
    for (int i =0;i<7;i++)
    {
        double sum_time = 0;
        for (int j =0;j<amount_tests;j++)
        {
            double* test_arr= rand_arr_create_with_in_d(size_arr[i],-1000000,1000000);
            shell_sort(test_arr,size_arr[i],sizeof(double),cmp_double);
            for (int k = 0; k < size_arr[i]-2; k++)
            {
                assert(test_arr[k]<=test_arr[k+1]);
            }
            sum_time=sum_time+((double)(end.QuadPart - start.QuadPart) / (double)frequency.QuadPart);
            free(test_arr);
        }
        printf("%d - avarage sort time: %lf",size_arr[i], sum_time/amount_tests);
        printf("\n");
    }
    
}