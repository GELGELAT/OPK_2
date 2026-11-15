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
    insert_check(tree, new_n);
}

static void left_rotate(Tree* tree, Node* x)
{
    if(x->right==NULL)
    return;
    Node* y = x->right; //опред у
    x->right=y->left; //передвинули левого жителя у
    if(x->right!=NULL)
    {
        x->right->parent=x; // определили отца жителя
    }
    y->parent=x->parent; // определили отца у
    if (x->parent ==NULL) // если он нул то это новый корень
    {
        tree->root=y;
    }
    else if(x->parent->left == x) // если х это левый житель отца переназначаем у
    {
        x->parent->left = y;
    }
    else 
    {
        x->parent->right = y;
    }
    y->left = x; //житель у теперь х
    x->parent = y;
}
static void right_rotate(Tree* tree, Node* x)
{
    if(x->left==NULL)return;
    Node* y = x->left;
    x->left=y->right;
    if(y->right)
    {
        x->left->parent=x;
    }
    
    if(!x->parent)
    {
        tree->root=y;
    }
    else if(x->parent->left==x)
    {
        x->parent->left=y;
    }
    else if(x->parent->right==x)
    {
        x->parent->right=y;
    }
    y->parent=x->parent;
    y->right=x;
    x->parent=y;
}

static void insert_check(Tree* tree,Node* n)
{
    if(!n->parent)
    {
        n->color=BLACK;
        return;
    }
    Node* c_n = n;
    while (c_n->parent != NULL && c_n->parent->color == RED)
    {
        Node* father = c_n->parent;
        Node* grandfather  = father->parent;
        if(grandfather->left==father)
        {
            Node* uncle = grandfather->right;
            if (uncle != NULL && uncle->color == RED)
            {
                father->color = BLACK;
                uncle->color = BLACK;
                grandfather->color = RED;
                c_n = grandfather;
            }
            else
            {
                if(father->right==c_n)
                {
                    c_n = father;
                    left_rotate(tree,c_n);
                }
                c_n->parent->color = BLACK;
                c_n->parent->parent->color = RED;
                right_rotate(tree,c_n->parent->parent);

            }
        }
        else
        {
            Node* uncle = grandfather->left;
            if (uncle != NULL && uncle->color == RED)
            {
                father->color = BLACK;
                uncle->color = BLACK;
                grandfather->color = RED;
                c_n = grandfather;
            }
            else
            {
                if(father->left==c_n)
                {
                    c_n = father;
                    right_rotate(tree,c_n);
                }
                c_n->parent->color = BLACK;
                c_n->parent->parent->color = RED;
                left_rotate(tree,c_n->parent->parent);
            }
        }

    }
    tree->root->color=BLACK;
}
