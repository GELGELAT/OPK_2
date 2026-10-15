#pragma once
#include "stdlib.h"
typedef void* vptr;

typedef struct Stack 
{
    vptr* stack;
    size_t tail_pos;
    size_t size,capacity;
} Stack;


Stack *stack_create();

void stack_print_stack(Stack *stack, size_t type_size);

void stack_destroy(Stack *stack);

size_t stack_size(Stack *stack);

void stack_push(Stack *stack, vptr elem);

vptr stack_peek(Stack *stack);

vptr stack_pop(Stack *stack);
