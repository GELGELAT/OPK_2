#pragma once

typedef struct Vector2D
{
    double x;
    double y;
}Vector2D;


Vector2D create_v2d(double x, double y);

char* to_str_v2d(Vector2D *vec);

Vector2D* add_v2d(Vector2D *v1, Vector2D *v2);

Vector2D* sub_v2d(Vector2D *v1, Vector2D *v2);

Vector2D* mul_v2d(Vector2D *v1, double scalar);

Vector2D* dot_v2d(Vector2D *v1, Vector2D *v2);

double len_v2d(Vector2D *v1);

double cross_v2d(Vector2D *v1, Vector2D *v2);

void normalize_v2d(Vector2D *v1, Vector2D *av);
