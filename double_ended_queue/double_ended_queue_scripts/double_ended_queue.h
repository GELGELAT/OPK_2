#pragma once
#include "stdlib.h"
typedef void* vptr;

typedef struct Deque 
{
    vptr* deque;
    size_t head_pos, tail_pos;
    size_t size,capacity;
} Deque;

Deque *deque_create(void);

static void deque_re_alloc(Deque *deque);

static size_t next_head_pos(Deque *deque);

static size_t next_tail_pos(Deque *deque);

Deque *deque_from_arr_to_deque(vptr *arr, size_t amount);

void deque_destroy(Deque *deque);

size_t deque_size(Deque *deque);

void deque_push_front(Deque *deque, vptr elem);

void deque_push_back(Deque *deque, vptr elem);

vptr deque_peek_front(Deque *deque);

vptr deque_peek_back(Deque *deque);

vptr deque_pop_front(Deque *deque);

vptr deque_pop_back(Deque *deque);
