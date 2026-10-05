#include "shell_sort.h"
#include "pointer_control.h"
#include "sort_comparators.h"
#include "string.h"
#include "math.h"
#include "speed_tests_scripts.h"
#include "any_type_arrays_work.h"
#include <stdbool.h>
#include<stdio.h>
int current_mode=SEDJVIK;
void shell_sort(void* array,size_t amount,size_t size,int (*cmp)( const void *a, const void *b))
{
    size_t gap_arr[20]={};
    size_t k=0;
    size_t gap_amount = 0;
    bool flag_build=0;
    if(current_mode==SHELL)
    {
        gap_arr[k]=gap_amount;k++;gap_amount = 1;gap_arr[k]=gap_amount;k++;
        while(!flag_build)
        {
            gap_amount = gap_amount*2;
            if(gap_amount<amount)
            {
                gap_arr[k]=gap_amount;
                k++;
            }
            else
            {
                flag_build=1;
            }
        }
        
    }
    else if (current_mode==HIBBARD)
    {
        while(!flag_build)
        {
            gap_amount = (int)pow(2,k)-1;
            if(gap_amount<amount)
            {
                gap_arr[k]=gap_amount;
                k++;
            }
            else
            {
                flag_build=1;
            }
        }
    }
    else if (current_mode==SEDJVIK)
    {
        size_t power_1=0;
        size_t power_2=2;
        size_t max_amount_1 =1;
        size_t max_amount_2 =0;
        bool flag_max_size=0;
        while(!flag_build)
        {
            //gap_amount = 9*pow(4,power_1)-9*pow(2,power_1)+1;
            //gap_amount = pow(4,power_2)-3*pow(2,power_2)+1;
            while(1)
            {
                gap_amount = 9*pow(4,power_1)-9*pow(2,power_1)+1;
                if(gap_amount< amount)
                {
                    max_amount_1++;
                    power_1++;
                }
                else break;
            }
            gap_amount=0;
            while(1)
            {
                gap_amount = pow(4,power_2)-3*pow(2,power_2)+1;
                if(gap_amount< amount)
                {
                    max_amount_2++;
                    power_2++;
                }
                else break;
            }
            int* form_1 = malloc(sizeof(int)*max_amount_1);
            int* form_2 = malloc(sizeof(int)*max_amount_2);
            gap_amount=0;
            size_t power_1=0;
            size_t power_2=2;
            form_1[0]=0;
            for(int i=1;i<max_amount_1;i++)
            {
                form_1[i]=9*pow(4,power_1)-9*pow(2,power_1)+1;
                power_1++;
            }
            for(int i=0;i<max_amount_2;i++)
            {
                form_2[i]=pow(4,power_2)-3*pow(2,power_2)+1;
                power_2++;
            }
            int* finish_arr= merger_arrays(form_1,max_amount_1,form_2,max_amount_2,sizeof(int));
            qsort(finish_arr,max_amount_1+max_amount_2,sizeof(int),cmp_int);
            k=max_amount_1+max_amount_2;
            for(int i=0;i<k;i++)
            {
                printf("%d ",finish_arr[i]);
            }
            flag_build=1;
        }
    }
    QueryPerformanceCounter(&start);
    size_t gap = gap_arr[--k];
    while(gap>0)
    {
        for(size_t i =gap;i<amount;i++)
        {
            void* temp = malloc(size);
            memcpy(temp,ptr_slid(array,size,i),size);
            size_t j = i;
            while (j>= gap )
            {
                if(cmp(ptr_slid(array,size,j-gap),temp)==-1)
                {
                    break;
                }
                swap_two_any(ptr_slid(array,size,j),ptr_slid(array,size,j-gap),size);
                j = j-gap;
            }
            swap_two_any(ptr_slid(array,size,j),temp,size);
            free(temp);
        }
        k--;
        gap = gap_arr[k];
    }
    QueryPerformanceCounter(&end); 
}
