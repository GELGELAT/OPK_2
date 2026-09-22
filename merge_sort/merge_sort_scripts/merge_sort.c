#include "merge_sort.h"
#include "pointer_control.h"
#include "sort_comparators.h"
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
            //последний первого куска
            //void* mid_arr = pointer_slider(array,size,tail+merge_width-1);
            size_t last_first_pos=start_first_pos+merge_width-1;
            //последний второго куска
            size_t last_second_pos_1 = start_first_pos+merge_width*2-1;
            size_t last_second_pos_2 = amount-1;
            size_t last_second_pos;
            if(cmp_size_t(last_second_pos_1,last_second_pos_2)==-1)
            {
                last_second_pos= last_second_pos_1;
            }
            else
            {
                last_second_pos= last_second_pos_2;
            }
            
            //ф слияния
            merge
            (
                pointer_slider(array,size,start_first_pos),
                pointer_slider(array,size,last_first_pos),
                pointer_slider(array,size,last_second_pos),
                size,cmp
            );
            start_first_pos = start_first_pos+2*merge_width;

        }
        merge_width = merge_width*2;
    }

}
void merge(void*start_first_ptr,void*last_first_ptr,void*last_second_pos,
size_t size,int (*cmp)( const void *a, const void *b))
{
    char*start_first_ptr_h=(char*)start_first_ptr;
    char*last_first_ptr_h=(char*)last_first_ptr;
    char*last_second_pos_h=(char*)last_second_pos;
}