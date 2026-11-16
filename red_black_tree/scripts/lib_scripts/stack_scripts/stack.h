#pragma once
#include <stddef.h>
typedef void* Pointer;

typedef struct Stack 
{
    Pointer* stack;
    size_t size,capacity;
} Stack;




void stack_create(Stack *stack);

void stack_destroy(Stack *stack);

size_t stack_size(Stack *stack);

void stack_push(Stack *stack, Pointer elem);

Pointer stack_peek(Stack *stack);

Pointer stack_pop(Stack *stack);
