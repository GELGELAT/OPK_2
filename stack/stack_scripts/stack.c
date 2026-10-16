#include "stack.h"
#include <stdio.h>
#include "stdlib.h"

void stack_create(Stack *stack)
{
    if(!stack)return;
    stack->stack=malloc(sizeof(vptr));
    if(!stack->stack)return;
    stack->tail_pos=0;
    stack->size=0;
    stack->capacity=1;
}
static void stack_re_alloc(Stack *stack)
{
    if(!stack)return;
    size_t new_capacity;
    new_capacity = stack->capacity*2;
    
    vptr* new_stack = malloc(sizeof(vptr)*new_capacity);
    if(!new_stack)return;
    for(int i=0;i<stack->size;i++)
    {
        new_stack[i]=stack->stack[i];
    }
    free(stack->stack);
    stack->stack=new_stack;
    stack->capacity=new_capacity;
}

void stack_destroy(Stack *stack)
{
    if(!stack)return;
    free(stack->stack);
    free(stack);
}
size_t stack_size(Stack *stack)
{
    if(!stack)return 0;
    return stack->size;
}

void stack_push(Stack *stack, vptr elem)
{
    if(!stack||!elem)return;
    if(stack->size+1>=stack->capacity)
    {
        stack_re_alloc(stack);
    }
    stack->stack[stack->tail_pos]=elem;
    stack->tail_pos++;
    stack->size++;
}

vptr stack_peek(Stack *stack)
{
    if(!stack)return NULL;
    return stack->stack[stack->tail_pos-1];
}

vptr stack_pop(Stack *stack)
{
    if(!stack)return NULL;
    vptr pop =stack->stack[stack->tail_pos-1];
    stack->tail_pos=stack->tail_pos-1;
    stack->size--;
    return pop;
}
