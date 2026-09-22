#include "selection_sort.h"

void selection_sort(void* array,size_t amount,size_t size,int (*cmp)( const void *a, const void *b))
{
    
    if (amount==0 || !array)
    {
        return;
    }
    char*main_arr = (char*)array;
    for (size_t i=0;i<amount-1;i++)
    {
        size_t min_index = i;
        const void* smallest = main_arr+ size*(min_index);
        for (size_t j = i+1; j < amount; j++)
        {
            
            const void* current = main_arr+ size*j;
            if(cmp(current,smallest)<0)
            {
                min_index = j;
                smallest = main_arr+ size*(min_index);
            }
        }
        if(min_index!=i)
        {
            const void*a = main_arr + i * size;
            swap_two_any(a,smallest,size);
        }
    }
}