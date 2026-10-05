#include "pointer_control.h"
void* ptr_slid(void* pointer, size_t size,size_t number_steps)
{
    char* ptr = (char*)pointer;
    return (void*)(ptr+size*number_steps);
}