#include "asserts_scripts.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
void matrix_assert_main_value(Matrix* test,double value)
{
    for (size_t i = 0; i < test->size_i; i++)
    {
        for (size_t j = 0; j < test->size_j; j++)
        {
            assert(test->matrix[i][j]==value);
        }
        
    }
    
}
void matrix_assert_identity(Matrix* test)
{
    for (size_t i = 0; i < test->size_i; i++)
    {
        for (size_t j = 0; j < test->size_j; j++)
        {
            if(i==j)
            {
                assert(test->matrix[i][j]==1);
            }
            else
            {
                assert(test->matrix[i][j]==0);
            }
            
        }
        
    }
}
void matrix_asserts()
{
    matrix_assert_create_zero();
    matrix_assert_create_identity();
    matrix_assert_create_constants();
    matrix_assert_multiply_subtract_add_multiply_scalar_divide_scalar();
    matrix_assert_is_valid_resize();
    matrix_assert_get_element_set_element();
    matrix_assert_set_identity_set_zero_set_constants();
    matrix_assert_set_identity_resize_set_zero_resize_set_constants_resize();
    matrix_assert_transpose_inverse_determinant();
}


void matrix_assert_create_zero()
{
    Matrix* test = matrix_create_zero(2,3);
    matrix_assert_main_value(test,0);
    matrix_destroy(test);
}
void matrix_assert_create_identity()
{
    Matrix* test = matrix_create_identity(4);
    for (size_t i = 0; i < test->size_i; i++)
    {
        for (size_t j = 0; j < test->size_j; j++)
        {
            if(i==j)
            {
                assert(test->matrix[i][j]==1);
            }
            else
            {
                assert(test->matrix[i][j]==0);
            }
            
        }
        
    }
    matrix_destroy(test);
}
void matrix_assert_create_constants()
{
    Matrix* test = matrix_create_constants(4,5,69);
    matrix_assert_main_value(test,69);
    matrix_destroy(test);
}
void matrix_assert_multiply_subtract_add_multiply_scalar_divide_scalar()
{
    Matrix* test = matrix_create_constants(4,5,69);
    Matrix* test1 = matrix_create_constants(4,5,1);
    matrix_add(test,test1);
    matrix_assert_main_value(test,70);
    matrix_subtract(test,test1);
    matrix_assert_main_value(test,69);
    matrix_multiply_scalar(test,10);
    matrix_assert_main_value(test,690);
    matrix_divide_scalar(test,10);
    matrix_assert_main_value(test,69);
    matrix_destroy(test);
    matrix_destroy(test1);
}
void matrix_assert_is_valid_resize()
{
    Matrix* test = matrix_create_empty();
    Matrix* test1 = matrix_create_identity(2);
    assert(matrix_is_valid(test)==false);
    assert(matrix_is_valid(test1)==true);
    printf("resize_test\n");
    matrix_print(test1);
    matrix_resize(test1,3,4);
    matrix_print(test1);

}
void matrix_assert_get_element_set_element()
{
    Matrix* test1 = matrix_create_identity(2);
    assert(matrix_get_element(test1,1,1)==1);
    matrix_set_element(test1,1,1,0);
    assert(matrix_get_element(test1,1,1)==0);
}
void matrix_assert_set_identity_set_zero_set_constants()
{
    Matrix* test1 = matrix_create(2,2);
    Matrix* test2 = matrix_create(2,3);
    Matrix* test3 = matrix_create(2,3);
    matrix_set_identity(test1);
    matrix_set_zero(test2);
    matrix_set_constants(test3,69);
    matrix_assert_main_value(test2,0);
    matrix_assert_main_value(test3,69);
}
void matrix_assert_set_identity_resize_set_zero_resize_set_constants_resize()
{
    Matrix* test1 = matrix_create_constants(2,3,69);
    matrix_set_identity_resize(test1,3);
    matrix_assert_identity(test1);

    matrix_set_zero_resize(test1,3,2);
    matrix_assert_main_value(test1,0);
    matrix_set_constants_resize(test1,3,4,69);
    matrix_assert_main_value(test1,69);
}
void matrix_assert_transpose_inverse_determinant()
{
    Matrix* test1 = matrix_create_identity(2);
    matrix_resize(test1,3,4);
    matrix_set_element(test1,1,4,69);
    printf("test_transpose\n");
    matrix_print(test1);
    Matrix* ntest1 =matrix_transpose(test1);
    matrix_print(ntest1);
}