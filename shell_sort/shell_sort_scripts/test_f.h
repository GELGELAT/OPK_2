#pragma once
#include <stddef.h>

void assert_sort_int(int *arr, size_t amount);

void assert_sort_float(float *arr, size_t amount);

void assert_sort_char(char *arr, size_t amount);

void assert_sort_double(double *arr, size_t amount);

void assert_sort_string(char **arr, size_t amount);

void int_test();

void float_test();

void char_test();

void double_test();

void string_test();
