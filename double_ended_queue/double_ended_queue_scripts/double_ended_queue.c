#include "double_ended_queue.h"

Deque* deque_create(void)
{
    Deque* deque = malloc(sizeof(Deque));
    //deque->deque = malloc(sizeof(vptr)*1);
    deque->head_pos=0;
    deque->tail_pos=0;
    deque->size=0;
    deque->capacity=0;
    return deque;
}
static void deque_re_alloc(Deque *deque)
{
    size_t new_capacity;
    if(deque->capacity==0)
    {
        new_capacity=1;
    }
    else
    {
        new_capacity = deque->capacity*2;
    }
    vptr* new_deque = malloc(sizeof(vptr)*new_capacity);
    for(int i=0;i<deque->capacity-deque->head_pos;i++)
    {

        new_deque[i]=deque->deque[deque->head_pos+i];
    }
    for(int i=0;i<deque->capacity;i++)
    {
        new_deque[i+deque->capacity-deque->head_pos+1]=deque->deque[deque->tail_pos-1-i];
    }
    free(deque->deque);
    deque->deque=new_deque;
    deque->capacity=new_capacity;
}
static size_t next_head_pos(Deque *deque)
{
    return (deque->head_pos-1+deque->capacity)%deque->capacity;
}
static size_t next_tail_pos(Deque *deque)
{
    return (deque->tail_pos+1)%deque->capacity;
}
Deque* deque_from_arr_to_deque(vptr* arr,size_t amount)
{
    Deque* deque = deque_create();
    for(int i=0;i<amount;i++)
    {
        deque_push_front(deque,arr[i]);
    }
    return deque;
}
void deque_print_deque(Deque* deque,size_t type_size)
{
    
}
void deque_destroy(Deque *deque)
{
    free(deque->deque);
    free(deque);
}
size_t deque_size(Deque *deque)
{
    return deque->size;
}
void deque_push_front(Deque *deque, vptr elem)
{
    deque->head_pos = next_head_pos(deque);
    deque->deque[deque->head_pos]=elem;
}
void deque_push_back(Deque *deque, vptr elem)
{
    deque->deque[deque->tail_pos]=elem;
    deque->tail_pos=next_tail_pos(deque);
}
vptr deque_peek_front(Deque *deque)
{
    return deque->deque[deque->head_pos];
}
vptr deque_peek_back(Deque *deque)
{
    return deque->deque[deque->tail_pos-1];
}
vptr deque_pop_front(Deque *deque)
{
    vptr pop =deque->deque[deque->head_pos];
    deque->head_pos=deque->head_pos+1;
    return pop;
}
vptr deque_pop_back(Deque *deque)
{
    vptr pop =deque->deque[deque->tail_pos-1];
    deque->tail_pos=deque->tail_pos-1;
    return pop;
}
