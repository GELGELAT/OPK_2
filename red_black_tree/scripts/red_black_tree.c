#include "red_black_tree.h"
#include <stdlib.h>
void tree_create(Tree *tree, CompareFunc cmp)
{
    tree->cmp=cmp;
    tree->root=NULL;
}
static Node* crt_n(Pointer value,int color,Pointer parent)
{
    Node* n = malloc(sizeof(Node));
    n->value = value;
    n->color =color;
    n->left =NULL;
    n->right =NULL;
    n->parent =parent;
    return n;
}
Pointer tree_insert(Tree *tree, Pointer data)
{
    Node* new_n = crt_n(data,RED,NULL);
    if(tree->root==NULL)
    {
        tree->root = new_n;
        tree->root->color = BLACK;
        return NULL;
    }
    else
    {
        Node* c_n = tree->root;
        Node* t_n = NULL;
        int cmp_i;
        while(c_n != NULL)
        {
            t_n = c_n;
            cmp_i = tree->cmp(data,c_n->value);
            
            if(cmp_i>0)
            {
                c_n = c_n->right;
            }
            else if (cmp_i<0)
            {
                c_n = c_n->left;
            }
            else
            {
                Pointer temp = t_n->value;
                t_n->value = data;
                return temp;
            }
        }
        new_n->parent = t_n;
        if(cmp_i>0)
        {
            t_n->right = new_n;
        }
        else
        {
            t_n->left = new_n;
        }
    }
    insert_check(new_n);
}
static insert_check(Node* n)
{
    if(n->parent==NULL)
    {

    }
}
