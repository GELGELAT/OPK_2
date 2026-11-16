#pragma once
#include "red_black_tree.h"
#include "rand_work_lib.h"
#include "sort_comparators.h"
#include <stdio.h>
typedef enum {FLOAT ,STRING} TYPE;

static Tree *from_arr_to_tree(void *arr, size_t amount, TYPE type_size, CompareFunc cmp);

static void print_tree_func_float(Pointer data, Pointer arg);

static void print_tree_func_string(Pointer data, Pointer arg);

static void print_tree(Tree *tree, TYPE type);

void compil_asserts();

void assert_tree_create();

void assert_tree_destroy();

void assert_tree_size();

void assert_tree_find();

void assert_tree_insert();

void assert_tree_delete();

void assert_tree_foreach();
