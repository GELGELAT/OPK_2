#include "charac.h"
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
    float arithmetic_mean_n;
    float sum=0;
    for (int i =0;i<amount;i++)
    {
        sum+=numbers_array[i];
    }
    return sum/amount;
}
float find_median(float* numbers_array, int amount)
{
    if(amount%2==0)
    {
        return (numbers_array[amount/2]+numbers_array[amount/2]+1)/2;
    }
    else
    {
        
        return numbers_array[amount/2];
    }
}
float find_root_mean_square_deviation(float* numbers_array, int amount, float arithmetic_mean)
{
    
    float sum=0;
    for (int i =0;i<amount;i++)
    {
        arg = numbers_array[amount]-arithmetic_mean;
        sum+=arg*arg;
    }
    float root_mean_square_deviation_n = sqrtf();
    return 

}
float find_maximum_consecutive_identical_elements(float* numbers_array, int amount)
{
    
}
float find_maximum_length_monotonic_segment(float* numbers_array, int amount)
{
    
}
float* characteristics_array_numbers(float* numbers_array, int amount)
{
    
    float maximum_consecutive_identical_elements_n;
    float maximum_length_monotonic_segment_n;

    float* charac_arr = malloc(sizeof(float)*7);
    charac_arr[0] = find_min(numbers_array,amount);
    charac_arr[1] = find_max(numbers_array,amount);
    charac_arr[2] = find_arithmetic_mean(numbers_array,amount);
    charac_arr[3] = find_median(numbers_array,amount);
    return charac_arr;
}
