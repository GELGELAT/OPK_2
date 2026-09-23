#ifndef CREATE_ARRAYS_H
#define CREATE_ARRAYS_H
#include <stddef.h>
float *create_rand_with_in_arr_f(size_t amount, float min, float max);

double *rand_arr_create_with_in_d(size_t amount, float min, float max);

int *rand_arr_create_with_in_int(size_t amount, int min, int max);

char *rand_arr_create_with_in_char(size_t amount, char min, char max);

char **rand_arr_create_with_in_string(size_t amount, int min_len, int max_len, char min, char max);

#endif

