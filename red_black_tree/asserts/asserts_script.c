#include "asserts_script.h"


static Tree* from_arr_to_tree(void* arr,size_t amount,TYPE type_size,CompareFunc cmp)
{
    char* arr_c = (char*)arr;
    Tree* tree = malloc(sizeof(Tree));
    if(!tree) return NULL;
    tree_create(tree,cmp);
    for (size_t i = 0; i < amount; i++)
    {
        tree_insert(tree,arr_c+type_size*i);
    }
    return tree;
}

static void print_tree_func_float(Pointer data, Pointer arg)
{
    printf("%f",*(float*)data);
}
static void print_tree_func_string(Pointer data, Pointer arg)
{
    printf("%s",(char*)data);
}
static void print_tree(Tree* tree,TYPE type)
{
    if(type==FLOAT)
    {
        tree_foreach(tree,print_tree_func_float,NULL);
    }
    else if (type==STRING)
    {
        tree_foreach(tree,print_tree_func_string,NULL);
    }
}
void compil_asserts()
{
    assert_tree_create();
    assert_tree_destroy();
    assert_tree_size();
    assert_tree_find();
    assert_tree_insert();
    assert_tree_delete();
    assert_tree_foreach();

}
void assert_tree_create()
{
    Tree* tree1 = malloc(sizeof(Tree));
    Tree* tree2 = malloc(sizeof(Tree));
    tree_create(tree1,cmp_float);
    tree_create(NULL,cmp_float);
    tree_create(tree2,NULL);
}
void assert_tree_destroy()
{
    
}
void assert_tree_size()
{
    
}
void assert_tree_find()
{
    
}
void assert_tree_insert()
{
    
}
void assert_tree_delete()
{
    
}
void assert_tree_foreach()
{
    
}