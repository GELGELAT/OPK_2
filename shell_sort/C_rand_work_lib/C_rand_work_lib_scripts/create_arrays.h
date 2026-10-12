#ifndef CREATE_ARRAYS_H
#define CREATE_ARRAYS_H

float *create_rand_with_in_arr_f(int amount, float min, float max);

double *rand_arr_create_with_in_d(int amount, float min, float max);

int *rand_arr_create_with_in_int(int amount, int min, int max);

char *rand_arr_create_with_in_char(int amount, char min, char max);

char **rand_arr_create_with_in_string(int amount, int min_len, int max_len, char min, char max);

#endif

