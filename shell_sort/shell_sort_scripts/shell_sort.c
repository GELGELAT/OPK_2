#include "shell_sort.h"
#include "pointer_control.h"
#include "sort_comparators.h"
#include "string.h"
#include "math.h"
#include "speed_tests_scripts.h"
#include "any_type_arrays_work.h"
#include <stdbool.h>
#include<stdio.h>
void shell_sort(int work_mode, void* array,size_t size,size_t type_size,int (*cmp)( const void *a, const void *b))
{
    int* finish_arr;
    int* gap_arr;
    size_t iter=0;
    size_t gap_size = size;
    size_t gap_amount = 0;
    if(work_mode==SHELL)
    {
        
        while(1)
        {
            gap_size = gap_size/2;
            if(gap_size<=0)
            {
                
                break;
            }
            gap_amount++;
        }
        finish_arr = malloc(sizeof(int)*(gap_amount+1));
        if (!finish_arr) return;
        gap_size = size;
        for (int i =0;i<gap_amount;i++)
        {
            gap_size = gap_size/2;
            finish_arr[i]=gap_size;
        }
        finish_arr[gap_amount]=0;
        
    }
    else if (work_mode==HIBBARD)
    {
        int power = 0;
        while(1)
        {
            gap_size = (int)pow(2,power)-1;
            if(gap_size<size)
            {
                gap_amount++;
                power++;
            }
            else
            {
                break;
            }
            
        }
        finish_arr = malloc(sizeof(int)*(gap_amount));
        if (!finish_arr) return;
        power=gap_amount-1;
        for(int i=0;i<gap_amount;i++)
        {
            gap_size = (int)pow(2,power)-1;
            power--;
            finish_arr[i]=gap_size;
        }
        
    }
    else if (work_mode==SEDJVIK)
    {
        size_t power_1=0;
        size_t power_2=2;
        size_t max_amount_1 =1;
        size_t max_amount_2 =0;
        
        //gap_amount = 9*pow(4,power_1)-9*pow(2,power_1)+1;
        //gap_amount = pow(4,power_2)-3*pow(2,power_2)+1;
        while(1)
        {
            gap_amount = 9*pow(4,power_1)-9*pow(2,power_1)+1;
            if(gap_amount< size)
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
            if(gap_amount< size)
            {
                max_amount_2++;
                power_2++;
            }
            else break;
        }
        int* form_1 = malloc(sizeof(int)*max_amount_1);
        if (!form_1) return;
        int* form_2 = malloc(sizeof(int)*max_amount_2);
        if (!form_1) return;
        gap_amount=0;
        power_1=0;
        power_2=2;
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
        finish_arr= merger_arrays(form_1,max_amount_1,form_2,max_amount_2,sizeof(int));
        qsort(finish_arr,max_amount_1+max_amount_2,sizeof(int),cmp_int_inv);
        gap_amount=max_amount_1+max_amount_2;
        free(form_1);
        free(form_2);
        
        
    }
    else if (work_mode==GEOMETRIC)
    {
        gap_size = size/2;
        int power =0;
        double k=5;
        while(1)
        {
            gap_size = size/2/(int)pow(k,power);
            //printf("%d",gap_size);
            if(gap_size>0)
            {
                gap_amount++;
                power++;
            }
            else break;
        }
        finish_arr = malloc(sizeof(int)*(gap_amount+1));
        if (!finish_arr) return;
        power=0;
        for(int i=0;i<gap_amount;i++)
        {
            gap_size = size/2/(int)pow(k,power);
            power++;
            finish_arr[i]=gap_size;
        }
        finish_arr[gap_amount]=0;
        
    }
    QueryPerformanceCounter(&start);
    size_t gap = finish_arr[iter];
    while(gap>0)
    {
        for(size_t i =gap;i<size;i++)
        {
            void* temp = malloc(type_size);
            memcpy(temp,ptr_slid(array,type_size,i),type_size);
            size_t j = i;
            while (j>= gap )
            {
                if(cmp(ptr_slid(array,type_size,j-gap),temp)==-1)
                {
                    break;
                }
                swap_two_any(ptr_slid(array,type_size,j),ptr_slid(array,type_size,j-gap),type_size);
                j = j-gap;
            }
            swap_two_any(ptr_slid(array,type_size,j),temp,type_size);
            free(temp);
        }
        gap = finish_arr[++iter];
    }
    QueryPerformanceCounter(&end); 
    free(finish_arr);
}
