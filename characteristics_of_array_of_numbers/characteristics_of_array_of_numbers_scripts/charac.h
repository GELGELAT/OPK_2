#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


typedef enum
{
    NONE =0,
    DOWN =-1,
    UP =1
}monotonic_segment_type;

float *characteristics_array_numbers(float *numbers_array, int amount);

float find_min(float *numbers_array, int amount);

float find_max(float *numbers_array, int amount);

float find_arithmetic_mean(float *numbers_array, int amount);

float find_median(float *numbers_array, int amount);

float find_root_mean_square_deviation(float *numbers_array, int amount, float arithmetic_mean);

int find_maximum_consecutive_identical_elements(float *numbers_array, int amount);

int find_maximum_length_monotonic_segment(float *numbers_array, int amount);
