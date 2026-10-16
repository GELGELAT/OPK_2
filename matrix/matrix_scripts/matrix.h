#pragma once
#include <stddef.h>
typedef double d;
typedef double* dp;

typedef struct Matrix
{
    dp* matrix;
    size_t size_i; //количество строк
    size_t size_j; //количество столбцов

} Matrix;

void matrix_print(Matrix *matrix);

Matrix *matrix_create_empty();

Matrix *matrix_create_vector(size_t cols);
