#include "merge_sort.h"
#include "pointer_control.h"
#include "sort_comparators.h"
#include "string.h"
void merge_sort(void* array,size_t amount,size_t size,int (*cmp)( const void *a, const void *b))
{
    //длинна куска
    size_t merge_width =1;
    while(merge_width<amount)
    {
        //начало первого куска индекс эл
        size_t start_first_pos=0;
        while (start_first_pos+merge_width<amount)
        {
            //количество в первом
            size_t amount_first = merge_width;
            //начало второго куска индекс эл
            size_t start_second_pos=start_first_pos+merge_width;
            size_t last_second_pos_1 = start_second_pos+merge_width-1;
            size_t last_second_pos_2 = amount-1;
            //количество во втором
            size_t amount_second;
            if(cmp_size_t(last_second_pos_1,last_second_pos_2)==-1)
            {
                amount_second= merge_width;
            }
            else
            {
                amount_second= last_second_pos_2-start_second_pos+1;
            }
            
            //ф слияния
            merge
            (
                array,start_first_pos,
                pointer_slider(array,size,start_first_pos),amount_first,
                pointer_slider(array,size,start_second_pos),amount_second,
                size,cmp
            );
            start_first_pos = start_first_pos+2*merge_width;

        }
        merge_width = merge_width*2;
    }

}
void merge(void* main_arr, size_t start_pos,
    void*start_first_ptr,size_t amount_first,
    void*start_second_ptr,size_t amount_second,
size_t size,int (*cmp)( const void *a, const void *b))
{
    void*copy_start_first_ptr = malloc(size*amount_first);
    //указатель выделеного массива для 1 куска
    copy_start_first_ptr= memcpy(copy_start_first_ptr,start_first_ptr,amount_first*size);
    void*copy_start_second_ptr = malloc(size*amount_second);
    //указатель выделеного массива для 2 куска
    copy_start_second_ptr= memcpy(copy_start_second_ptr,start_second_ptr,amount_second*size);

    size_t first_step=0;
    size_t second_step=0;
    size_t pos_in_arr_step=start_pos;

    while(first_step<amount_first&&second_step<amount_second)
    {
        void* current_first =pointer_slider(copy_start_first_ptr,size,first_step);
        void* current_second = pointer_slider(copy_start_second_ptr,size,second_step);
        void* current_arr_ptr = pointer_slider(main_arr,size,pos_in_arr_step);
        if(cmp(current_first,current_second)<=0)
        {
            
            memcpy(current_arr_ptr,current_first,size);
            first_step++;
        }
        else
        {
            memcpy(current_arr_ptr,current_second,size);
            second_step++;
        }
        pos_in_arr_step++;
    }
    while (first_step<amount_first)
    {
        void* current_first =pointer_slider(copy_start_first_ptr,size,first_step);
        void* current_arr_ptr = pointer_slider(main_arr,size,pos_in_arr_step);
        memcpy(current_arr_ptr,current_first,size);
        first_step++;
        pos_in_arr_step++;
    }
    while (second_step<amount_second)
    {
        void* current_second =pointer_slider(copy_start_second_ptr,size,second_step);
        void* current_arr_ptr = pointer_slider(main_arr,size,pos_in_arr_step);
        memcpy(current_arr_ptr,current_second,size);
        second_step++;
        pos_in_arr_step++;
    }
    free(copy_start_first_ptr);
    free(copy_start_second_ptr);

}