#pragma once

typedef struct Vector2D
{
    double x;
    double y;
}Vector2D;
typedef struct Vector3D
{
    double x;
    double y;
    double z;
}Vector3D;

Vector2D create_v2d(double x, double y);

void to_str_v2d(Vector2D *vec);

void add_v2d(Vector2D *v1, Vector2D *v2, Vector2D *av);

void sub_v2d(Vector2D *v1, Vector2D *v2, Vector2D *av);

void mul_v2d(Vector2D *v1, double scalar, Vector2D *av);

void dot_v2d(Vector2D *v1, Vector2D *v2, Vector2D *av);

double len_v2d(Vector2D *v1);

void cross_v2d(Vector2D *v1, Vector2D *v2, Vector3D *av);

void normalize_v2d(Vector2D *v1, Vector2D *av);
