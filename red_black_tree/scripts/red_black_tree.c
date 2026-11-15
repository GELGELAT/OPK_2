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
        Node* del_node = tree->root;
        Node* t_n = NULL;
        int cmp_i;
        while(del_node != NULL)
        {
            t_n = del_node;
            cmp_i = tree->cmp(data,del_node->value);
            
            if(cmp_i>0)
            {
                del_node = del_node->right;
            }
            else if (cmp_i<0)
            {
                del_node = del_node->left;
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

static void left_rotate(Tree* tree, Node* n)
{
    if(n->right==NULL)
    return;
    Node* y = n->right; //опред у
    n->right=y->left; //передвинули левого жителя у
    if(n->right!=NULL)
    {
        n->right->parent=n; // определили отца жителя
    }
    y->parent=n->parent; // определили отца у
    if (n->parent ==NULL) // если он нул то это новый корень
    {
        tree->root=y;
    }
    else if(n->parent->left == n) // если х это левый житель отца переназначаем у
    {
        n->parent->left = y;
    }
    else 
    {
        n->parent->right = y;
    }
    y->left = n; //житель у теперь х
    n->parent = y;
}
static void right_rotate(Tree* tree, Node* n)
{
    if(n->left==NULL)return;
    Node* y = n->left;
    n->left=y->right;
    if(y->right)
    {
        n->left->parent=n;
    }
    
    if(!n->parent)
    {
        tree->root=y;
    }
    else if(n->parent->left==n)
    {
        n->parent->left=y;
    }
    else if(n->parent->right==n)
    {
        n->parent->right=y;
    }
    y->parent=n->parent;
    y->right=n;
    n->parent=y;
}

static void insert_check(Tree* tree,Node* n)
{
    if(!n->parent)
    {
        n->color=BLACK;
        return;
    }
    Node* del_node = n;
    while (del_node->parent != NULL && del_node->parent->color == RED) // так как вставка красная проверяем до тех пор пока родитель красный
    {
        Node* father = del_node->parent; //отец
        Node* grandfather  = father->parent; //дед
        if(grandfather->left==father)//определяем случай нужно для поворотов 
        {
            Node* uncle = grandfather->right;
            if (uncle != NULL && uncle->color == RED)//определяем случай
            //первый дядя красный второй дядя чрный
            {
                father->color = BLACK;
                uncle->color = BLACK;
                grandfather->color = RED;
                del_node = grandfather;// перекраска + занаво проверка для деда не нарушена ли цветовая схема
            }
            else
            {//случай если дед чрный 
                if(father->right==del_node)//приводим из зигзагообразного вида к прямому
                {
                    del_node = father;
                    left_rotate(tree,del_node);
                }
                del_node->parent->color = BLACK;//перекраска + поворот
                del_node->parent->parent->color = RED;
                right_rotate(tree,del_node->parent->parent);
            }
        }
        else
        {//тожесамое зеркально
            Node* uncle = grandfather->left;
            if (uncle != NULL && uncle->color == RED)
            {
                father->color = BLACK;
                uncle->color = BLACK;
                grandfather->color = RED;
                del_node = grandfather;
            }
            else
            {
                if(father->left==del_node)
                {
                    del_node = father;
                    right_rotate(tree,del_node);
                }
                del_node->parent->color = BLACK;
                del_node->parent->parent->color = RED;
                left_rotate(tree,del_node->parent->parent);
            }
        }

    }
    tree->root->color=BLACK;
}


Pointer tree_delete(Tree *tree, Pointer data)
{
    if(tree->root==NULL)
    {
        return NULL;

    }
    else
    {
        Node* del_node =tree->root;

        while(del_node != NULL)
        {//сначала поиск удаляемого нода как в бст
            int cmp_i = tree->cmp(data, del_node->value);
            if(cmp_i>0)
            del_node = del_node->right;
            else if (cmp_i<0)
            del_node = del_node->left;
            else
            {//нашли узел
                Color deleted_color = del_node->color;//цвет для проверки
                Pointer temp_value = del_node->value;
                 Node* child = NULL; //ребнок типа приемник
                Node* child_parent = NULL;//его батя

                //нет детей
                if(del_node->left==NULL && del_node->right ==NULL)
                {
                    child_parent = del_node->parent;
                    if (!del_node->parent)
                    {
                        tree->root=NULL;

                    }
                    else if(del_node->parent->left== del_node)
                    {
                        del_node->parent->left=NULL;
                    }
                    else
                    {
                        del_node->parent->right= NULL;
                    }
                    //не забыть балансировку
                    free(del_node);
                    
                    if (deleted_color==BLACK) 
                    {
                        
                        delete_check(tree, NULL, child_parent); 
                    }


                    return temp_value;
                }
                else if(!del_node->left )
                {//один ребенок првый жив
                    child  =del_node->right;
                    child_parent =del_node->parent;

                    if (!del_node->parent)
                    {
                        tree->root =child;
                        child->parent =NULL;
                    }
                    else 
                    {
                        if (del_node->parent->left==del_node)
                        del_node->parent->left=child;
                        else
                        del_node->parent->right=child;
                        child->parent= del_node->parent;
                    }
                    free(del_node);

                    if (deleted_color ==BLACK) 
                    {
                        delete_check(tree,child,child_parent);
                    }
                    return temp_value;
                }
                else if (del_node->right==NULL)
                {//зеркально для левого
                    child = del_node->left;
                    child_parent =del_node->parent;

                    if (!del_node->parent)
                    {
                        tree->root=child;
                        child->parent=NULL;
                    }
                    else 
                    {
                        if (del_node->parent->left==del_node)
                            del_node->parent->left=child;
                        else
                        del_node->parent->right=child;
                        child->parent=del_node->parent;
                    }
                    free(del_node);
                    if (deleted_color == BLACK) 
                    {
                        delete_check(tree, child, child_parent);
                    }
                    return temp_value;
                }
                else
                {//два ребенка
                    Node*temp_node = del_node->right;
                    Node*receiver_node =NULL;
                    while(temp_node)
                    {
                        receiver_node=temp_node;
                        temp_node=temp_node->left;
                    }
                    
                    //даные приемника 
                    del_node->value =receiver_node->value;
                    deleted_color =receiver_node->color;    

                    child =receiver_node->right;//справа тк уже самый правый
                    child_parent =receiver_node->parent;
                    if(del_node->right== receiver_node)//проверка на порядок
                    {
                        del_node->right =child;
                        if (child) 
                        child->parent =del_node;
                        child_parent = del_node;//обновили
                    }
                    else
                    {
                        
                        
                        receiver_node->parent->left = child;
                        if (child) child->parent = receiver_node->parent;
                    }
                    free(receiver_node);
                    
                    if (deleted_color == BLACK) 
                    {
                        delete_check(tree, child, child_parent);
                    }
                    
                    return temp_value;
                }
            }
        }
    }
    return NULL;
}
void delete_check(Tree* tree, Node* n, Node* parent_n)
{
    
    //случай черный черный обрабатываем 4 случая
    while (n != tree->root && (n == NULL || n->color == BLACK))
    {
        if (parent_n != NULL && n == parent_n->left)//смотрим если слева
        {
            Node* brother_node = parent_n->right;

            //1 брат красный
            if (brother_node != NULL && brother_node->color == RED)
            {
                brother_node->color = BLACK;
                parent_n->color = RED;
                left_rotate(tree, parent_n);
                brother_node = parent_n->right;//новый брат см рисунок
            }

            // 2 все черные и брат и его дети
            // определяем цвет каждого ребенка брата
            int b_left_black = (brother_node == NULL || brother_node->left == NULL || brother_node->left->color == BLACK);
            int b_right_black = (brother_node == NULL || brother_node->right == NULL || brother_node->right->color == BLACK);

            if (b_left_black && b_right_black)
            {
                if (brother_node != NULL) 
                {
                    brother_node->color = RED;
                }
                n = parent_n;
                parent_n = n->parent;
                //в черный отца не красим чтобы нормально выйти из цыкла
            }
            else
            {
                // 3 брат черный правый ребенок черный левый красный
                if (brother_node != NULL && brother_node->left != NULL 
                    && brother_node->left->color == RED)
                {
                    brother_node->left->color = BLACK;
                    brother_node->color = RED;
                    right_rotate(tree, brother_node);
                    brother_node = parent_n->right;//меняем брата
                }

                // случай 4 брат правый красный
                if (brother_node != NULL)
                {
                    brother_node->color = parent_n->color;
                    if (brother_node->right != NULL) 
                    {
                        brother_node->right->color = BLACK;
                    }
                }
                parent_n->color = BLACK;
                left_rotate(tree, parent_n);
                
                n = tree->root; // завершение цикла плюс покрас корня в черный для выполн свойства
            }
        }
        else if (parent_n != NULL) //симетрия случай если n стоит справа
        {
            Node* brother_node = parent_n->left;


            if (brother_node != NULL && brother_node->color == RED)
            {
                brother_node->color = BLACK;
                parent_n->color = RED;
                right_rotate(tree, parent_n);
                brother_node = parent_n->left;
            }

            int b_left_black = (brother_node == NULL || brother_node->left == NULL || brother_node->left->color == BLACK);
            int b_right_black = (brother_node == NULL || brother_node->right == NULL || brother_node->right->color == BLACK);

            if (b_left_black && b_right_black)
            {
                if (brother_node != NULL) brother_node->color = RED;
                n = parent_n;
                parent_n = n->parent;
            }
            else
            {
                if (brother_node != NULL && brother_node->right != NULL 
                    && brother_node->right->color == RED)
                {
                    if (brother_node->right != NULL) brother_node->right->color = BLACK;
                    brother_node->color = RED;
                    left_rotate(tree, brother_node);
                    brother_node = parent_n->left;
                }

                if (brother_node != NULL)
                {
                    brother_node->color = parent_n->color;
                    if (brother_node->left != NULL) brother_node->left->color = BLACK;
                }
                parent_n->color = BLACK;
                right_rotate(tree, parent_n);
                
                n = tree->root;
            }
        }
    }
    //покраска корня
    if (n != NULL)
    {
        n->color = BLACK;
        return;
    }
    
}
Pointer tree_find(Tree *tree, Pointer data)
{
    if(tree->root==NULL)
    {
        return NULL;
    }
    else
    {
        Node* del_node = tree->root;
        while(del_node != NULL)
        {
            int cmp_i = tree->cmp(data,del_node->value);
            
            if(cmp_i>0)
            {
                del_node = del_node->right;
            }
            else if (cmp_i<0)
            {
                del_node = del_node->left;
            }
            else
            {
                return del_node->value;
            }
        }
    }
    return NULL;
}
