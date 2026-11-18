#pragma once
#include "red_black_tree.h"
#include "rand_work_lib.h"
#include "sort_comparators.h"
#include <stdio.h>
typedef enum {FLOAT ,STRING} TYPE;





void compil_asserts();

void assert_tree_create();

void assert_tree_destroy();

void assert_tree_size();

void assert_tree_find();

void assert_tree_insert_delete();



void assert_tree_foreach();
