#include "test_f.h"
#include <assert.h>
#include "selection_sort.h"
#include <stdio.h>
#include "rand_work_lib.h"
//test_
int j=0;
void assert_sort_int(int* arr,int amount)
{
    j++;
    printf("%d\n",j);
    selection_sort(arr,amount,sizeof(int),cmp_int);
    if (amount==0)
    {
        return;
    }
    for (size_t i = 0; i < amount-1; i++)
    {
        assert(arr[i]<=arr[i+1]);
    }
    
}
void assert_sort_float(float* arr,int amount)
{
    j++;
    printf("%d\n",j);
    selection_sort(arr,amount,sizeof(float),cmp_float);
    if (amount==0)
    {
        return;
    }
    for (size_t i = 0; i < amount-1; i++)
    {
        assert(arr[i]<=arr[i+1]);
    }
    
}
void assert_sort_char(char* arr,int amount)
{
    j++;
    printf("%d\n",j);
    selection_sort(arr,amount,sizeof(char),cmp_char);
    if (amount==0)
    {
        return;
    }
    for (size_t i = 0; i < amount-1; i++)
    {
        assert(arr[i]<=arr[i+1]);
    }
    
}
void assert_sort_double(double* arr,int amount)
{
    j++;
    printf("%d\n",j);
    selection_sort(arr,amount,sizeof(double),cmp_double);
    if (amount==0)
    {
        return;
    }
    for (size_t i = 0; i < amount-1; i++)
    {
        assert(arr[i]<=arr[i+1]);
    }
    
}
void assert_sort_string(char** arr,int amount)
{
    j++;
    printf("%d\n",j);
    selection_sort(arr,amount,sizeof(char*),cmp_string);
    if (amount==0)
    {
        return;
    }
    for (size_t i = 0; i < amount-1; i++)
    {
        int len1=0;
        int len2=0;
        while (arr[i][len1]!='\0')
        {
            len1+=1;
        }
        while (arr[i+1][len2]!='\0')
        {
            len2+=1;
        }
        assert(len1<=len2);
    }
    
}
void int_test()
{
    int test_r[] = {5,69,-69,0,1};
    int test_0[] = {};
    int test_1[] = {9};
    int test_2[] = {9,0};
    int test_d1[] = {9,8,9,-8,-8};
    int test_d2[] = {0,0,0,0,0};
    int test_m1[] = {1,2,3,4,5};
    int test_m2[] = {5,4,3,2,1};
    assert_sort_int(test_r,5);
    assert_sort_int(test_0,0);
    assert_sort_int(test_1,1);
    assert_sort_int(test_2,2);
    assert_sort_int(test_d1,5);
    assert_sort_int(test_d2,5);
    assert_sort_int(test_m1,5);
    assert_sort_int(test_m2,5);
    int* big_test = rand_arr_create_with_in_int(100,-100,100);
    assert_sort_int(big_test,100);
    
}
void float_test()
{
    float test_r[] = {5,69,-69,0,1};
    float test_0[] = {};
    float test_1[] = {9};
    float test_2[] = {9,0};
    float test_d1[] = {9,8,9,-8,-8};
    float test_d2[] = {0,0,0,0,0};
    float test_d3[] = {0.6,0.7,0.1,0.2,0.1};
    float test_m1[] = {1.6,2,3,4,5};
    float test_m2[] = {5,4,3,2,1};
    assert_sort_float(test_r,5);
    assert_sort_float(test_0,0);
    assert_sort_float(test_1,1);
    assert_sort_float(test_2,2);
    assert_sort_float(test_d1,5);
    assert_sort_float(test_d2,5);
    assert_sort_float(test_d3,5);
    assert_sort_float(test_m1,5);
    assert_sort_float(test_m2,5);
    float* big_test = create_rand_with_in_arr_f(100,-100,100);
    assert_sort_float(big_test,100);
}
void char_test()
{
    char test_r[] = "bacab";
    char test_0[] = {};
    char test_1[] = "b";
    char test_2[] = "ba";
    char test_d1[] = "babbb";
    char test_d2[] = "bbbbb";
    char test_m1[] = "abcd";
    char test_m2[] = "dbcd";
    assert_sort_char(test_r,5);
    assert_sort_char(test_0,0);
    assert_sort_char(test_1,1);
    assert_sort_char(test_2,2);
    assert_sort_char(test_d1,5);
    assert_sort_char(test_d2,5);
    assert_sort_char(test_m1,4);
    assert_sort_char(test_m2,4);
    char* big_test = rand_arr_create_with_in_char(100,'a','z');
    assert_sort_char(big_test,100);
    
}
void double_test()
{
    double test_r[] = {5,69,-69,0,1};
    double test_0[] = {};
    double test_1[] = {9};
    double test_2[] = {9,0};
    double test_d1[] = {9,8,9,-8,-8};
    double test_d2[] = {0,0,0,0,0};
    double test_d3[] = {0.6,0.7,0.1,0.2,0.1};
    double test_m1[] = {1.6,2,3,4,5};
    double test_m2[] = {5,4,3,2,1};
    assert_sort_double(test_r,5);
    assert_sort_double(test_0,0);
    assert_sort_double(test_1,1);
    assert_sort_double(test_2,2);
    assert_sort_double(test_d1,5);
    assert_sort_double(test_d2,5);
    assert_sort_double(test_d3,5);
    assert_sort_double(test_m1,5);
    assert_sort_double(test_m2,5);
    double* big_test = rand_arr_create_with_in_d(100,-100,100);
    assert_sort_double(big_test,100);
    
}
void string_test()
{
    char* test_r[] = {"asd","a","as"};
    char* test_0[] = {};
    char *test_1[] = {"bad"};
    char *test_2[] = {"asd","fd"};
    char *test_d1[] = {"asd","sdf","dfg"};

    assert_sort_string(test_r,3);
    assert_sort_string(test_0,0);
    assert_sort_string(test_1,1);
    assert_sort_string(test_2,2);
    assert_sort_string(test_d1,3);
    char** big_test = rand_arr_create_with_in_string(100,0,100,'a','z');
    assert_sort_string(big_test,100);
 
    
}