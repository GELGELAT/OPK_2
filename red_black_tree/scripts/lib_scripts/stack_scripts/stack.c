#include "stack.h"
#include <stdio.h>
#include "stdlib.h"

void stack_create(Stack *stack)
{
    if(!stack)return;
    stack->stack=malloc(sizeof(Pointer));
    if(!stack->stack)
    {
        printf("error");
        return;
    }
        stack->size=0;
    stack->capacity=1;
}
static void stack_re_alloc(Stack *stack)
{
    if(!stack)return;
    size_t new_capacity;
    if((float)stack->size/stack->capacity<0.5)
    {
        new_capacity = (size_t)((double)stack->capacity/1.5)+1;
    }
    else if(stack->size+1>=stack->capacity)
    {
        new_capacity = stack->capacity*2;
    }
    else
    {
        return;
    }
    stack->stack=realloc(stack->stack,new_capacity*sizeof(Pointer));
    stack->capacity=new_capacity;
}

void stack_destroy(Stack *stack)
{
    if(!stack)return;
    free(stack->stack);
}
size_t stack_size(Stack *stack)
{
    if(!stack)return 0;
    return stack->size;
}

void stack_push(Stack *stack, Pointer elem)
{
    if(!stack||!elem)return;
    stack_re_alloc(stack);
    stack->stack[stack->size]=elem;
    stack->size++;
}

Pointer stack_peek(Stack *stack)
{
    if(!stack)return NULL;
    return stack->stack[stack->size-1];
}

Pointer stack_pop(Stack *stack)
{
    if(!stack)return NULL;
    
    Pointer pop =stack->stack[stack->size-1];
    stack->size--;
    stack_re_alloc(stack);
    return pop;
}
