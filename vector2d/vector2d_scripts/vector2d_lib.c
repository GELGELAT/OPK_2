#include "vector2d_lib.h"
#include <stdio.h>
#include <math.h>
Vector2D create_v2d(double x,double y)
{
    return (Vector2D){x,y};
}

void to_str_v2d(Vector2D* vec)
{
    if(!vec) return;
    printf("x: %lf|y: %lf\n",vec->x,vec->y);

}

void add_v2d(Vector2D* v1,Vector2D*v2,Vector2D* av)
{
    if(!v1||!v2||!av) return;
    av->x=v1->x+v2->x;
    av->y=v1->y+v2->y;
}
void sub_v2d(Vector2D* v1,Vector2D* v2,Vector2D* av)
{
    if(!v1||!v2||!av) return;
    av->x=v1->x-v2->x;
    av->y=v1->y-v2->y;
}
void mul_v2d(Vector2D* v1,double scalar,Vector2D* av)
{
    if(!v1||!av) return;
    av->x=v1->x*scalar;
    av->y=v1->y*scalar;
}
void dot_v2d(Vector2D* v1,Vector2D* v2,Vector2D* av)
{
    if(!v1||!v2||!av) return;
    av->x=v1->x*v2->x;
    av->y=v1->y*v2->y;
}
double len_v2d(Vector2D* v1)
{
    if(!v1) return 0;
    return sqrt((v1->x *v1->x)+(v1->y *v1->y));
}
void cross_v2d(Vector2D* v1,Vector2D* v2,Vector3D* av)
{
    if(!v1||!v2||!av) return;
    av->x= 0;
    av->y=0;
    av->z=v1->x*v2->y-v1->y*v2->x;

}
void normalize_v2d(Vector2D* v1,Vector2D* av)
{
    if(!v1) return;
    double x =v1->x;
    double y= v1->y;
    double len = len_v2d(v1);
    av->x=x/len;
    av->y=y/len;

}