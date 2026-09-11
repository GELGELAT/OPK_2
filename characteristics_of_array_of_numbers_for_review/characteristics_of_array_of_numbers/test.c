#include "charac.h"
#define ARR_AMOUNT_TEST 2
#define NUMBERS_AMOUNT_TEST 5
int main(void)
{
    float test_arr[ARR_AMOUNT_TEST][NUMBERS_AMOUNT_TEST] = 
    {
        {1,2,3,4,5},
        {1,2,69,4,5}
    };
    for (int i=0;i<ARR_AMOUNT_TEST;i++)
    {
        float* chara_arr = characteristics_array_numbers(test_arr[i],NUMBERS_AMOUNT_TEST);
        for (int j =0;j<7;j++)
        {
            printf("%f\t",chara_arr[j]);
        }
        printf("\n");
    }
}