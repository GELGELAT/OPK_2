
#include <stdio.h>
#include "speed_tests_scripts.h"
#include "shell_sort.h"
#include "create_arrays.h"
#include "sort_comparators.h"
int main(void) 
{
    
    //tests();
    shell_sort(rand_arr_create_with_in_d(50000,10,1),50000,sizeof(double),cmp_double);
    
}