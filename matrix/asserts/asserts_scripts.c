#include "asserts_scripts.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort_comparators.h"

Matrix* matrix_from_arr_to_mat(double* arr,size_t rows, size_t cols)
{
    Matrix* mat=matrix_create(rows,cols);
    if(!mat)return NULL;
    size_t iter = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            
            mat->matrix[i][j]=arr[iter];
            iter++;
        }
        
    }
    return mat;
}
void matrix_print(Matrix* matrix)
{
    if(matrix==NULL)
    {
        printf("NULL\n");
        return;
    }
    for (size_t i = 0; i < matrix->size_i; i++)
    {
        for (size_t j = 0; j < matrix->size_j; j++)
        {
            printf("%lf ",matrix->matrix[i][j]);
        }
        printf("\n");
    }
    
}
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
    matrix_assert_create_zero_create_empty_create_vector_create();
    matrix_assert_create_identity();
    matrix_assert_create_constants();
    matrix_assert_multiply_subtract_add_multiply_scalar_divide_scalar();
    matrix_assert_is_valid_resize();
    matrix_assert_get_element_set_element();
    matrix_assert_set_identity_set_zero_set_constants();
    matrix_assert_set_identity_resize_set_zero_resize_set_constants_resize();
    matrix_assert_transpose_inverse_determinant();
}


void matrix_assert_create_zero_create_empty_create_vector_create()
{
    Matrix* test = matrix_create_empty();
    Matrix* test2 = matrix_create_vector(10);
    Matrix* test3 = matrix_create_vector(0);
    Matrix* test4 = matrix_create(69,9);
    Matrix* test6 = matrix_create(69,0);
    Matrix* test1 = matrix_create_zero(2,3);
    Matrix* test5 = matrix_create_zero(2,0);
    matrix_assert_main_value(test1,0);
    matrix_destroy(test);
    matrix_destroy(test1);
    matrix_destroy(test2);
    matrix_destroy(test3);
    matrix_destroy(test4);
    matrix_destroy(test5);
    matrix_destroy(test6);
    matrix_destroy(NULL);
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
    Matrix* test2 = matrix_create_identity(0);
    matrix_destroy(test);
    matrix_destroy(test2);
}
void matrix_assert_create_constants()
{
    Matrix* test = matrix_create_constants(4,5,69);
    Matrix* test1 = matrix_create_constants(4,0,69);
    matrix_assert_main_value(test,69);
    matrix_destroy(test);
    matrix_destroy(test1);
}
void matrix_assert_multiply_subtract_add_multiply_scalar_divide_scalar()
{
    double mat1[]={4,6,3,1,6,6};
    double mat2[]={1,9,9,9,2,9};
    Matrix* testm1 = matrix_from_arr_to_mat(mat1,3,2);
    Matrix* testm2 = matrix_from_arr_to_mat(mat2,2,3);
    Matrix* testm = matrix_multiply(testm1,testm2);
    printf("multiply test\n");
    matrix_print(testm);
    Matrix* test = matrix_create_constants(4,5,69);
    Matrix* test1 = matrix_create_constants(4,5,10);
    Matrix* ntest1 = matrix_add(test,test1);
    Matrix* ntes11 = matrix_add(test,NULL);
    matrix_assert_main_value(ntest1,79);
    Matrix* ntest2 = matrix_subtract(test,test1);
    Matrix* ntest21 = matrix_subtract(NULL,test1);
    matrix_assert_main_value(ntest2,59);
    Matrix* ntest3 = matrix_multiply_scalar(test,10);
    Matrix* ntest31 = matrix_multiply_scalar(NULL,10);
    matrix_assert_main_value(ntest3,690);
    Matrix* ntest4 = matrix_divide_scalar(ntest3,10);
    Matrix* ntest41 = matrix_divide_scalar(ntest3,0);
    matrix_assert_main_value(ntest4,69);
    matrix_destroy(test);
    matrix_destroy(test1);
    matrix_destroy(ntest1);
    matrix_destroy(ntes11);
    matrix_destroy(ntest2);
    matrix_destroy(ntest21);
    matrix_destroy(ntest3);
    matrix_destroy(ntest31);
    matrix_destroy(ntest4);
    matrix_destroy(ntest41);

}
void matrix_assert_is_valid_resize()
{
    Matrix* test = matrix_create_empty();
    Matrix* test1 = matrix_create_identity(2);
    matrix_is_valid(NULL);
    assert(matrix_is_valid(test)==false);
    assert(matrix_is_valid(test1)==true);
    printf("resize_test\n");
    matrix_print(test1);
    matrix_resize(test1,3,4);
    matrix_resize(test1,0,4);
    printf("->\n");
    matrix_print(test1);
    matrix_destroy(test);
    matrix_destroy(test1);

}
void matrix_assert_get_element_set_element()
{
    Matrix* test1 = matrix_create_identity(2);
    matrix_get_element(test1,1,2);
    assert(matrix_get_element(test1,1,1)==1);
    matrix_set_element(test1,1,1,0);
    matrix_set_element(test1,1,2,0);
    assert(matrix_get_element(test1,1,1)==0);
    matrix_destroy(test1);
}
void matrix_assert_set_identity_set_zero_set_constants()
{
    Matrix* test1 = matrix_create(2,2);
    Matrix* test2 = matrix_create(2,3);
    Matrix* test3 = matrix_create(2,3);
    matrix_set_identity(test1);
    matrix_set_identity(NULL);
    matrix_set_zero(test2);
    matrix_set_zero(NULL);
    matrix_set_constants(test3,69);
    matrix_set_constants(NULL,69);
    matrix_assert_main_value(test2,0);
    matrix_assert_main_value(test3,69);
    matrix_destroy(test1);
    matrix_destroy(test2);
    matrix_destroy(test3);
}
void matrix_assert_set_identity_resize_set_zero_resize_set_constants_resize()
{
    Matrix* test1 = matrix_create_constants(2,3,69);
    matrix_set_identity_resize(test1,3);
    matrix_set_identity_resize(test1,0);
    matrix_assert_identity(test1);

    matrix_set_zero_resize(test1,3,2);
    matrix_set_zero_resize(test1,3,0);
    matrix_assert_main_value(test1,0);
    matrix_set_constants_resize(test1,3,4,69);
    matrix_set_constants_resize(test1,0,4,69);
    matrix_assert_main_value(test1,69);
        matrix_destroy(test1);

}
void matrix_assert_transpose_inverse_determinant()
{
    Matrix* test1 = matrix_create_identity(2);
    matrix_resize(test1,3,4);
    matrix_set_element(test1,1,4,69);
    printf("test_transpose\n");
    matrix_print(test1);
    Matrix* ntest1 =matrix_transpose(test1);
    matrix_transpose(NULL);
        printf("->\n");

    matrix_print(ntest1);
    Matrix* test2 = matrix_create_identity(3);
    assert(matrix_determinant(test2)==1);
    matrix_set_element(test2,3,1,69);
    matrix_set_element(test2,1,3,1);
    assert(matrix_determinant(test2)==-68);
    matrix_set_element(test2,2,1,1);
    matrix_set_element(test2,3,1,1);
    assert(matrix_determinant(test2)==0);
    matrix_determinant(NULL);
    printf("inverse_test\n");
    Matrix* itest = matrix_create(2,2);
    matrix_set_element(itest,1,1,2);
    matrix_set_element(itest,1,2,9);
    matrix_set_element(itest,2,1,2);
    matrix_set_element(itest,2,2,4);
    matrix_print(itest);
        printf("->\n");

    Matrix* itest1=matrix_inverse(itest);
    matrix_print(itest1);
    matrix_set_element(itest,1,1,1);
    matrix_set_element(itest,1,2,1);
    matrix_set_element(itest,2,1,1);
    matrix_set_element(itest,2,2,1);
    Matrix* itest2=matrix_inverse(itest);
    matrix_print(itest2);
    matrix_destroy(test1);
    matrix_destroy(ntest1);
    matrix_destroy(test2);
    matrix_destroy(itest);
    matrix_destroy(itest2);
    matrix_destroy(itest1);
    printf("inverse_test_big\n");
    double big1[] =
    {
        8,1,9,6,
        6,2,5,4,
        1,5,6,9,
        6,6,6,8
    };
    Matrix* big_m1=matrix_from_arr_to_mat(big1,4,4);
    printf("->\n");
    Matrix* imat=matrix_inverse(big_m1);
    matrix_print(imat);
    printf("Big test\n");
    double big[] =
    {
        9,6,5,5,5,
        6,5,2,8,9,
        96,9,5,0,1,
        38,3,2,0,2,
        2,7,2,6,5
    };
    Matrix* big_m=matrix_from_arr_to_mat(big,5,5);
    d det = matrix_determinant(big_m);
    d det_1=-10642;
    assert(cmp_double(&det,&det_1)==0);
}