#pragma once
#include <stdlib.h>

typedef void *Pointer;
typedef int (*CompareFunc)(Pointer a, Pointer b);

typedef enum {BLACK ,RED} Color;

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


Pointer tree_insert(Tree *tree, Pointer data);




Pointer tree_delete(Tree *tree, Pointer data);


Pointer tree_find(Tree *tree, Pointer data);

size_t tree_size(Tree *tree);

void tree_destroy(Tree *tree);

void tree_foreach(Tree *tree, void (*func)(Pointer data, void *arg), void *arg);
