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