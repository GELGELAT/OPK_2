#include "vector2d_lib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
Vector2D create_v2d(double x,double y)
{
    return (Vector2D){x,y};
}

char* to_str_v2d(Vector2D* vec)
{
    if(!vec) return NULL;
    double x=vec->x;
    double y=vec->y;

    int size = snprintf(NULL, 0, "%lf %lf", x,y); //snprintf возращ кол симвл которая бы записала
    char *ans = malloc(size + 1);
    snprintf(ans, size + 1, "%lf %lf", x,y);
    return ans;


}

Vector2D* add_v2d(Vector2D* v1,Vector2D*v2)
{
    if(!v1||!v2) return NULL;
    v1->x=v1->x+v2->x;
    v1->y=v1->y+v2->y;
}
Vector2D* sub_v2d(Vector2D* v1,Vector2D* v2)
{
    if(!v1||!v2) return NULL;
    v1->x=v1->x-v2->x;
    v1->y=v1->y-v2->y;
}
Vector2D* mul_v2d(Vector2D* v1,double scalar)
{
    if(!v1) return NULL;
    v1->x=v1->x*scalar;
    v1->y=v1->y*scalar;
}
Vector2D* dot_v2d(Vector2D* v1,Vector2D* v2)
{
    if(!v1||!v2) return NULL;
    v1->x=v1->x*v2->x;
    v1->y=v1->y*v2->y;
}
double len_v2d(Vector2D* v1)
{
    if(!v1) return 0;
    return sqrt((v1->x *v1->x)+(v1->y *v1->y));
}
double cross_v2d(Vector2D* v1,Vector2D* v2)
{
    if(!v1||!v2) return 0;
    double ans = v1->x*v2->y-v1->y*v2->x;
    if(ans<0)
    {
        return -ans;
    }
    return ans;

}
void normalize_v2d(Vector2D* v1,Vector2D* av)
{
    if(!v1) return;
    double len = len_v2d(v1);
    av->x=v1->x/len;
    av->y=v1->y/len;

}