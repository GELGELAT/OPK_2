#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
void matrix_print(Matrix* matrix)
{
    for (size_t i = 0; i < matrix->size_i; i++)
    {
        for (size_t j = 0; j < matrix->size_j; j++)
        {
            printf("%lf ",matrix->matrix[i][j]);
        }
        printf("\n");
    }
    
}

Matrix* matrix_create_empty()
{
    Matrix* m = malloc(sizeof(Matrix));
    if(!m)return NULL;
    return m;
}
Matrix* matrix_create_vector(size_t cols)
{
    if (cols == 0) return NULL;
    Matrix* m=malloc(sizeof(Matrix));
    if(!m)return NULL;
    m->matrix=malloc(sizeof(dp));
    if(!m->matrix)
    {
        free(m);
        return NULL;
    }
    m->matrix[0] = malloc(cols*sizeof(d));
    if(!m->matrix[0])
    {
        free(m->matrix);
        free(m);
        return NULL;
    }
    m->size_i=1;
    m->size_j=cols;
    return m;
}
