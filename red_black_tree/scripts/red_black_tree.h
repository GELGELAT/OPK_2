#pragma once
#include <stdbool.h>
typedef void *Pointer;
typedef int (*CompareFunc)(Pointer a, Pointer b);

typedef enum {BLACK ,RED  } Color;

typedef struct Node {
    Pointer value;
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct tTree
{
    Node* root;
    CompareFunc cmp;
} Tree;

void tree_create(Tree *tree, CompareFunc cmp);

static Node *crt_n(Pointer value, int color, Pointer parent);

Pointer tree_insert(Tree *tree, Pointer data);

static void left_rotate(Tree *tree, Node *x);

static void right_rotate(Tree *tree, Node *x);

static void insert_check(Tree *tree, Node *n);


static void delete_check(Tree *tree, Node *main, Node *parent);

Pointer tree_find(Tree *tree, Pointer data);
