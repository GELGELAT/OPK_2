/*
#include "rand_work_lib.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main(void)
{
    int amount = 10;
    srand((unsigned)time(NULL) ^ GetTickCount());

    
    char** arr = rand_arr_create_with_in_string(10,1,10,'a','z');
    for (int j =0;j<amount;j++)
    {
        printf("%s ",arr[j]);
    }
        
}
*/