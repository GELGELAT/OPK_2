#include "asserts_script.h"
#include "stack.h"
#include "assert.h"
static void tree_print_float_with_color(Tree *tree)
{
    if (!tree||!tree->root)
    return;
    Stack* stack = malloc(sizeof(Stack));
    stack_create(stack);
    Node* cur_node = tree->root;
    while(cur_node||stack->size>0)
    {
        while(cur_node)
        {
            stack_push(stack, cur_node);
            cur_node=cur_node->left;
        }
        cur_node = stack_pop(stack);
        printf("%f:%d ",*(float*)cur_node->value,cur_node->color);
        cur_node=cur_node->right;
    }
    stack_destroy(stack);
    free(stack);
    printf("\n");
    return;
}
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
    printf("%f ",*(float*)data);
}
static void print_tree_func_string(Pointer data, Pointer arg)
{
    printf("%s ",*(char**)data);
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
    float arr1[] = {10,5,20,3};
    Tree* tree1 =from_arr_to_tree(arr1,4,sizeof(float),cmp_float);
    assert(tree_size(tree1)==4);
}
void assert_tree_find()
{
    
}
void assert_tree_insert()
{
    printf("assert_tree_insert\n");
    printf("1) uncle: red\n");
    float arr1[] = {10,5,20,3};
    Tree* tree1 =from_arr_to_tree(arr1,4,sizeof(float),cmp_float);
    tree_print_float_with_color(tree1);
    printf("2) uncle: black\n");
    float a = 6;
    tree_insert(tree1,&a);
    tree_delete(tree1,&arr1[2]);
    tree_print_float_with_color(tree1);
    tree_destroy(tree1);

 /*
    float* arrbig1 = create_rand_with_in_arr_f(1000,-100,100);
    Tree* tree_big1 =from_arr_to_tree(arrbig1,1000,sizeof(float),cmp_float); 
    char** arrbig2 = rand_arr_create_with_in_string(1000,1,40,'1','9');
    Tree* tree_big2 =from_arr_to_tree(arrbig2,1000,sizeof(char*),cmp_string); 
    tree_destroy(tree_big1);
    tree_destroy(tree_big2);
    */
}
void assert_tree_delete()
{
    float arr1[] = {10,5,20,3};
    Tree* tree1 =from_arr_to_tree(arr1,4,sizeof(float),cmp_float);
    float a = 6;
    tree_insert(tree1,&a);
    tree_delete(tree1,&arr1[2]);
    tree_print_float_with_color(tree1);
    tree_destroy(tree1);
}
void assert_tree_foreach()
{
    
}