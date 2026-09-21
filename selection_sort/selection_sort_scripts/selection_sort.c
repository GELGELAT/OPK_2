#include "selection_sort.h"

void selection_sort(void* array,int amount,size_t size,int (*cmp)( const void *a, const void *b))
{
    char*main_arr = (char*)array;
    for (int i=0;i<amount-1;i++)
    {
        int min_index = i;
        
        for (int j = i+1; j < amount; j++)
        {
            void* smallest = main_arr+ size*(min_index);
            void* current = main_arr+ size*j;
            if(cmp(current,smallest)<0)
            {
                min_index = j;
                
            }
        }
        if(min_index!=i)
        {
            void*a = main_arr + i * size;
            void*b = main_arr + min_index * size;
            swap_two_any(a,b,size);
        }
    }
}