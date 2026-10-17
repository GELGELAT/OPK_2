#pragma once
#include <stddef.h>
#include <stdbool.h>

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

Matrix *matrix_create(size_t rows, size_t cols);

Matrix *matrix_create_zero(size_t rows, size_t cols);

Matrix *matrix_create_identity(size_t size);

Matrix *matrix_create_constants(size_t rows, size_t cols, double value);

void matrix_destroy(Matrix *mat);

void matrix_add(Matrix *mat1, Matrix *mat2);

void matrix_subtract(Matrix *mat1, Matrix *mat2);

void matrix_multiply_scalar(Matrix *mat, double value);

void matrix_divide_scalar(Matrix *mat, double value);

bool matrix_is_valid(Matrix *mat);

void matrix_resize(Matrix *mat, size_t rows, size_t cols);

double matrix_get_element(Matrix *mat, size_t rowIdx, size_t colIdx);

void matrix_set_element(Matrix *mat, size_t rowIdx, size_t colIdx, double value);

void matrix_set_identity(Matrix *mat);

void matrix_set_zero(Matrix *mat);

void matrix_set_constants(Matrix *mat, double value);

void matrix_set_identity_resize(Matrix *mat, size_t size);

void matrix_set_zero_resize(Matrix *mat, size_t rows, size_t cols);

void matrix_set_constants_resize(Matrix *mat, size_t rows, size_t cols, double value);

Matrix* matrix_transpose(Matrix *mat);
