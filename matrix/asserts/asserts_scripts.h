#pragma once
#include "matrix.h"

void matrix_print(Matrix *matrix);

void matrix_assert_main_value(Matrix *test, double value);
void matrix_asserts();


void matrix_assert_create_zero_create_empty_create_vector_create();

void matrix_assert_create_identity();

void matrix_assert_create_constants();

void matrix_assert_multiply_subtract_add_multiply_scalar_divide_scalar();

void matrix_assert_is_valid_resize();

void matrix_assert_get_element_set_element();

void matrix_assert_set_identity_set_zero_set_constants();

void matrix_assert_set_identity_resize_set_zero_resize_set_constants_resize();

void matrix_assert_transpose_inverse_determinant();
