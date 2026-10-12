#include "any_type_arrays_work.h"
#include <stdlib.h>
#include <string.h>
void* merger_arrays(void* first_arr,size_t amount_1,void*second_arr,size_t amount_2,size_t elem_size)
{
    void* merg_arr = malloc(elem_size*(amount_1+amount_2));
    if(!merg_arr) return NULL;
    memcpy(merg_arr,first_arr,amount_1*elem_size);
    memcpy((char*)merg_arr+amount_1*elem_size,second_arr,amount_2*elem_size);
    return merg_arr;
}
