#include "vector2d_asserts.h"
#include "vector2d_lib.h"
#include <stdio.h>
#include <assert.h>
#include "sort_comparators.h"
#include <math.h>
void main_test()
{
    create_to_str_v2d_assert();
    add_v2d_assert();
    sub_v2d_assert();
    mul_v2d_assert();
    dot_v2d_assert();
    len_v2d_assert();
    cross_v2d_assert();
    normalize_v2d_assert();
}

void create_to_str_v2d_assert()
{
    Vector2D v1 = create_v2d(10,-10);
    to_str_v2d(&v1);
}

void add_v2d_assert()
{
    Vector2D v1 = create_v2d(10,-10);
    Vector2D v2 = create_v2d(-10,10);
    Vector2D av;
    add_v2d(&v1,&v2,&av);
    add_v2d(NULL,&v2,&av);
    assert((av.x)==0);
    assert((av.y)==0);
}
void sub_v2d_assert()
{
    Vector2D v1 = create_v2d(10,-10);
    Vector2D v2 = create_v2d(-10,10);
    Vector2D av;
    sub_v2d(&v1,&v2,&av);
    sub_v2d(NULL,&v2,&av);
    assert((av.x)==20);
    assert((av.y)==-20);
}
void mul_v2d_assert()
{
    Vector2D v1 = create_v2d(10,-10);
    Vector2D av;
    mul_v2d(&v1,-10,&av);
    mul_v2d(NULL,-10,&av);
    assert((av.x)==-100);
    assert((av.y)==100);
}
void dot_v2d_assert()
{
    Vector2D v1 = create_v2d(10,-10);
    Vector2D v2 = create_v2d(-10,10);
    Vector2D av;
    dot_v2d(&v1,&v2,&av);
    dot_v2d(NULL,&v2,&av);
    assert((av.x)==-100);
    assert((av.y)==-100);
}
void len_v2d_assert()
{
    Vector2D v1 = create_v2d(6,-8);
    len_v2d(NULL);
    assert(len_v2d(&v1)==10);

}
void cross_v2d_assert()
{
    Vector2D v1 = create_v2d(1,1);
    Vector2D v2 = create_v2d(2,1);
    Vector3D av;
    cross_v2d(NULL,&v2,&av);
    cross_v2d(&v1,&v2,&av);
    assert(av.x==0);
    assert(av.y==0);
    assert(av.z==-1);

}
void normalize_v2d_assert()
{
    Vector2D v1 = create_v2d(1,-1);
    Vector2D av;
    normalize_v2d(&v1,&av);
    normalize_v2d(NULL,&av);
    double tx = 1/sqrt(2);
    double ty = -1/sqrt(2);
    assert(cmp_double(&av.x,&tx)==0);
    assert(cmp_double(&av.y,&ty)==0);

}