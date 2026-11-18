#include "asserts_script.h"
#include "stack.h"
#include "assert.h"
static Tree *from_arr_to_tree(void *arr, size_t amount, TYPE type_size, CompareFunc cmp);

static void print_tree_func_float(Pointer data, Pointer arg);

static void print_tree_func_string(Pointer data, Pointer arg);

static void print_tree(Tree *tree, TYPE type);

static void balance_check(Tree *tree)
{
    Node* n = tree->root;
    size_t first_bh = 0;
    size_t second_bh = 0;
    while (n)
    {
        if(n->color==BLACK)
        first_bh +=1;
        size_t turn = rand_with_in_int(0,1);
        if(turn == 0) n=n->left;
        else n=n->right;
    }
    n = tree->root;
     while (n)
    {
        if(n->color==BLACK)
        second_bh +=1;
        size_t turn = rand_with_in_int(0,1);
        if(turn == 0) n=n->left;
        else n=n->right;
    }
    printf("%d, %d",first_bh,second_bh);
    printf("\n");
    return;
}

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
    assert_tree_insert_delete();
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
    float arr1[] = {10,5,20,3};
    Tree* tree1 =from_arr_to_tree(arr1,4,sizeof(float),cmp_float);
    tree_destroy(tree1);
    tree_destroy(NULL);
}
void assert_tree_size()
{
    float arr1[] = {10,5,20,3};
    Tree* tree1 =from_arr_to_tree(arr1,4,sizeof(float),cmp_float);
    assert(tree_size(tree1)==4);
    assert(tree_size(NULL)==0);
}
void assert_tree_find()
{
    float arr1[] = {10,5,20,3};
    Tree* tree1 =from_arr_to_tree(arr1,4,sizeof(float),cmp_float);
    assert((*(float*)tree_find(tree1,&arr1[1]))==5);
    assert(tree_find(tree1,NULL)==NULL);
    assert(tree_find(NULL,&arr1[1])==NULL);
}
void assert_tree_insert_delete()
{
    printf("assert_tree_insert\n");

    float arr1[] = {10,5,20,3};
    Tree* tree1 =from_arr_to_tree(arr1,4,sizeof(float),cmp_float);
    tree_print_float_with_color(tree1);
    printf("2 \n");
    float a = 6;
    tree_insert(tree1,&a);
    tree_delete(tree1,&arr1[2]);
    tree_print_float_with_color(tree1);
    tree_delete(NULL,&arr1[2]);
    tree_delete(tree1,NULL);
    tree_insert(NULL,&arr1[2]);
    tree_insert(tree1,NULL);
    float b = 9;
    float c = 9;
    assert(tree_insert(tree1,&b)==NULL);
    assert((float*)tree_insert(tree1,&c)==&b);
    assert((float*)tree_delete(tree1,&c)==&c);
    assert((float*)tree_delete(tree1,&c)==NULL);
    tree_destroy(tree1);

    float arr2[] = {10,5,20,3,14,8,9,12};
    Tree* tree2 =from_arr_to_tree(arr1,8,sizeof(float),cmp_float);
    balance_check(tree2);
 
    float* arrbig1 = create_rand_with_in_arr_f(1000,-100,100);
    Tree* tree_big1 =from_arr_to_tree(arrbig1,1000,sizeof(float),cmp_float); 
    balance_check(tree_big1);
    char** arrbig2 = rand_arr_create_with_in_string(1000,1,40,'1','9');
    Tree* tree_big2 =from_arr_to_tree(arrbig2,1000,sizeof(char*),cmp_string); 

    
    tree_destroy(tree_big1);
    tree_destroy(tree_big2);
    
}
static void test_func(Pointer data, void *arg)
{
    float* sum = (float*)arg;
    *sum+= *(float*)data;
}
void assert_tree_foreach()
{
    float arr1[] = {10,5,20,3};
    Tree* tree1 =from_arr_to_tree(arr1,4,sizeof(float),cmp_float);
    float a = 0;
    tree_foreach(tree1,test_func,&a);
    assert(a==38);
    tree_foreach(NULL,test_func,&a);
    tree_foreach(tree1,NULL,&a);
    tree_foreach(tree1,test_func,NULL);
}