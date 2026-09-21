#include "selection_sort.h"

void selection_sort(void* array,int amount,size_t size,int (*cmp)( const void *a, const void *b))
{
    char*main_arr = (char*)array;
    for (int i=0;i<amount-1;i++)
    {
        void* smallest = main_arr+ size*(i);
        for (int j = i+1; j < amount; j++)
        {
            void* current = main_arr+ size*j;
            if(cmp(current,smallest)==-1)
            {
                swap_two_any(current,smallest,size);
            }
        }
        
    }
}