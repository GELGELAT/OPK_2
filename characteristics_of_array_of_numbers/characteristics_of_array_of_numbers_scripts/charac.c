#include "charac.h"
#include "sort_work_lib.h"
#include <stdlib.h>
/*
1 Минимальное число
2 Максимальное число
3 Среднее арифметическое
4 Медиана
5 СКО
6 Максимальное число идущих подряд одинаковых элементов
7 Максимальная длина монотонного участка
*/


float find_min(float* numbers_array, int amount)
{
    float min_n = numbers_array[0];
    for (int i =0;i<amount;i++)
    {
        if (min_n>numbers_array[i])
        {
            min_n =numbers_array[i];
        }
    }
    return min_n;
}
float find_max(float* numbers_array, int amount)
{
    float max_n= numbers_array[0];
    for (int i =0;i<amount;i++)
    {
        if (max_n<numbers_array[i])
        {
            max_n =numbers_array[i];
        }
    }
    return max_n;
}
float find_arithmetic_mean(float* numbers_array, int amount)
{
    float sum=0;
    for (int i =0;i<amount;i++)
    {
        sum+=numbers_array[i];
    }
    return sum/amount;
}
float find_median(float* numbers_array, int amount)
{
    float* copy_array = malloc(sizeof(float)*amount);
    if(copy_array==NULL)
    {
        return NAN;
    }
    float median;
    for (int i=0;i<amount;i++)
    {
        copy_array[i]=numbers_array[i];
    }
    qsort(copy_array,amount,sizeof(float),cmp_float);
    if(amount%2==0)
    {
        median = (copy_array[amount/2-1]+copy_array[amount/2])/2;
        free(copy_array);
        return median;
    }
    else
    {
        
        median= copy_array[amount/2];
        free(copy_array);
        return median;
    }
}
float find_root_mean_square_deviation(float* numbers_array, int amount, float arithmetic_mean)
{
    
    float sum=0;
    for (int i =0;i<amount;i++)
    {
        float arg = numbers_array[i]-arithmetic_mean;
        sum+=arg*arg;
    }
    float root_mean_square_deviation_n = sqrtf(sum/amount);
    return root_mean_square_deviation_n;

}
int find_maximum_consecutive_identical_elements(float* numbers_array, int amount)
{
    int identical_elements =1;
    int max_identical_elements = 1;
    float current;
    float old = numbers_array[0];
    for (int i =1;i<amount;i++)
    {
        current=numbers_array[i];
        if (current==old)
        {
            identical_elements++;
            if (identical_elements>max_identical_elements)
            {
                max_identical_elements =identical_elements;
            }
        }
        else
        {
            identical_elements=1;
        }
        old=current;
    }
    return max_identical_elements;
}
int find_maximum_length_monotonic_segment(float* numbers_array, int amount)
{
    int monotonic_segment =1;
    int max_monotonic_segment = 1;
    int monotonic_segment_type = NONE;
    int current_monotonic_segment_type = NONE;
    float current;
    float old = numbers_array[0];
    for (int i =1;i<amount;i++)
    {
        current=numbers_array[i];
        if(current > old)
        {
            current_monotonic_segment_type = UP;
        }
        else if(current< old)
        {
            current_monotonic_segment_type = DOWN;
        }
        if (monotonic_segment_type == NONE)
        {
            monotonic_segment_type = current_monotonic_segment_type;
        }
        if (monotonic_segment_type == current_monotonic_segment_type)
        {
            monotonic_segment++;
            if (monotonic_segment>max_monotonic_segment)
            {
                max_monotonic_segment =monotonic_segment;
            }
        }
        else
        {
            monotonic_segment=1;
            monotonic_segment_type = current_monotonic_segment_type;
        }
        old=current;
    }
    return max_monotonic_segment;
}
float* characteristics_array_numbers(float* numbers_array, int amount)
{
    if (amount == 0)
    {
        return NULL;
    }
    float* charac_arr = malloc(sizeof(float)*7);
    charac_arr[0] = find_min(numbers_array,amount);
    charac_arr[1] = find_max(numbers_array,amount);
    charac_arr[2] = find_arithmetic_mean(numbers_array,amount);
    charac_arr[3] = find_median(numbers_array,amount);
    charac_arr[4] = find_root_mean_square_deviation(numbers_array,amount,charac_arr[2]);
    charac_arr[5] = find_maximum_consecutive_identical_elements(numbers_array,amount);
    charac_arr[6] = find_maximum_length_monotonic_segment(numbers_array,amount);

    return charac_arr;
}
