#include "charac.h"
#include "rand_work_lib.h"
#include <time.h>
#include <stdio.h>
#include <windows.h>

#define ARR_AMOUNT_TEST 9
#define NUMBERS_AMOUNT_TESTS 10
int main(void)
{
    srand((unsigned)time(NULL) ^ GetTickCount());
    float test_arr[ARR_AMOUNT_TEST][NUMBERS_AMOUNT_TESTS] = 
    {
        {5,9,69,7,-69},
        {2,2,2,2,2},
        {-1,-1,-3,-3,-3},
        {1,2,-69,-10,-5},
        {-1,-1,-1,-1,-1},
        {},
        {69},
        {1,2,3,1},
        {2,3}
    };
    int numbers_amount_test[ARR_AMOUNT_TEST] = 
    {
        5,5,5,5,5,0,1,4,2
    };
    char* str[ARR_AMOUNT_TEST] = {"min -69, max 69","SKO 0","ident_elem 3","monotonic 3","any","amount 0","one",
    "median 2.5","median 2.5"};
    for (int i=0;i<ARR_AMOUNT_TEST;i++)
    {
        
        float* chara_arr = characteristics_array_numbers(test_arr[i],numbers_amount_test[i]);
        if (chara_arr==NULL)
        {
            printf("%s","amount = 0");
            printf("\n");
            continue;
        }
        printf("%s - ",str[i]);
        for (int j =0;j<7;j++)
        {
            printf("%d)%f\t",j+1,chara_arr[j]);
        }
        printf("\n");
    }
    int big_amount = 1000;
    float* big_arr = create_rand_with_in_arr_f(big_amount,-100,100);
    float* chara_for_big_arr = characteristics_array_numbers(big_arr,big_amount);
    printf("%s","big arr");
    for (int j =0;j<7;j++)
    {
        printf("%d)%f\t",j+1,chara_for_big_arr[j]);
    }

}