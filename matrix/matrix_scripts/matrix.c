#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void matrix_print(Matrix* matrix)
{
    if(matrix==NULL)
    {
        printf("NULL\n");
        return;
    }
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
    Matrix* m = calloc(1,sizeof(Matrix));
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
Matrix* matrix_create(size_t rows, size_t cols)
{
    if (cols == 0||rows == 0) return NULL;
    Matrix* m=malloc(sizeof(Matrix));
    if(!m)return NULL;
    m->matrix=malloc(sizeof(dp)*rows);
    if(!m->matrix)
    {
        free(m);
        return NULL;
    }
    for (size_t i = 0; i < rows; i++)
    {
        m->matrix[i] = malloc(sizeof(d)*cols);
        if(!m->matrix[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(m->matrix[j]);
            }
            free(m->matrix);
            free(m);
            return NULL;
        }
    }
    
    m->size_i=rows;
    m->size_j=cols;
    return m;
    
}
Matrix* matrix_create_zero(size_t rows, size_t cols)
{
    if (cols == 0||rows == 0) return NULL;
    Matrix* m=malloc(sizeof(Matrix));
    if(!m)return NULL;
    m->matrix=malloc(sizeof(dp)*rows);
    if(!m->matrix)
    {
        free(m);
        return NULL;
    }
    for (size_t i = 0; i < rows; i++)
    {
        m->matrix[i] = calloc(cols,sizeof(d));
        if(!m->matrix[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(m->matrix[j]);
            }
            free(m->matrix);
            free(m);
            return NULL;
        }
    }
    m->size_i=rows;
    m->size_j=cols;
    return m;
}
Matrix* matrix_create_identity(size_t size)
{
    if(size==0)return NULL;
    Matrix* m = matrix_create_zero(size,size);
    for (size_t i = 0; i < size; i++)
    {
        m->matrix[i][i]=1;    
    }
    return m;
}
Matrix* matrix_create_constants(size_t rows, size_t cols, double value)
{
    if (cols == 0||rows == 0) return NULL;
    Matrix* m = matrix_create_zero(rows,cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            m->matrix[i][j]=value;    
        }  
    }
    return m;
}
void matrix_destroy(Matrix* mat)
{
    if(!mat)return;
    for (size_t i = 0; i < mat->size_i; i++)
    {
        free(mat->matrix[i]);
    }
    free(mat->matrix);
    free(mat);
}
 Matrix* matrix_add(Matrix* mat1, Matrix* mat2)
{
    if(!mat1||!mat2)return NULL;
    Matrix* nmat = matrix_create(mat1->size_i,mat1->size_j);
    if(mat1->size_i!=mat2->size_i||mat1->size_j!=mat2->size_j) return NULL;
    for (size_t i = 0; i < mat1->size_i; i++)
    {
        for (size_t j = 0; j < mat1->size_j; j++)
        {
            nmat->matrix[i][j]=mat1->matrix[i][j]+mat2->matrix[i][j];
        }
        
    }
    return nmat;
}
 Matrix* matrix_subtract(Matrix* mat1, Matrix* mat2)
{
    if(!mat1||!mat2)return NULL;
    Matrix* nmat = matrix_create(mat1->size_i,mat1->size_j);
    if(mat1->size_i!=mat2->size_i||mat1->size_j!=mat2->size_j) return NULL;
    for (size_t i = 0; i < mat1->size_i; i++)
    {
        for (size_t j = 0; j < mat1->size_j; j++)
        {
            nmat->matrix[i][j]=mat1->matrix[i][j]-mat2->matrix[i][j];
        }
        
    }
    return nmat;
}
Matrix* matrix_multiply_scalar(Matrix* mat, double value)
{
    if(!mat)return NULL;
    Matrix* nmat = matrix_create(mat->size_i,mat->size_j);
    if(!mat) return NULL;
    for (size_t i = 0; i < mat->size_i; i++)
    {
        for (size_t j = 0; j < mat->size_j; j++)
        {
            nmat->matrix[i][j]=mat->matrix[i][j]*value;
        }
        
    }
    return nmat;

}
Matrix* matrix_divide_scalar(Matrix* mat, double value)
{
    if(!mat||value==0)return NULL;
    Matrix* nmat = matrix_create(mat->size_i,mat->size_j);
    if(!mat) return NULL;
    for (size_t i = 0; i < mat->size_i; i++)
    {
        for (size_t j = 0; j < mat->size_j; j++)
        {
            nmat->matrix[i][j]=mat->matrix[i][j]/value;
        }
        
    }
    return nmat;

}

bool matrix_is_valid(Matrix* mat)
{
    if(!mat)return false;
    if(mat->matrix==NULL||mat->size_i==0||mat->size_j==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void matrix_resize(Matrix* mat, size_t rows, size_t cols)
{
    if(!mat||rows==0||cols==0)return;
    dp* nmatrix = calloc(rows,sizeof(dp));
    if(!nmatrix)return;
    for (size_t i = 0; i < rows; i++)
    {
        nmatrix[i] = calloc(cols,sizeof(d));
        if(!nmatrix[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(nmatrix[j]);
            }
            free(nmatrix);
            return;
        }
    }
    size_t cop_i;
    size_t cop_j;
    if(mat->size_i>=rows)
    {
        cop_i=rows;
    }
    else
    {
        cop_i=mat->size_i;
    }
    if(mat->size_j>=cols)
    {
        cop_j=cols;
    }
    else
    {
        cop_j=mat->size_j;
    }
    for (size_t i = 0; i < cop_i; i++)
    {
        for (size_t j = 0; j < cop_j; j++)
        {
            nmatrix[i][j]=mat->matrix[i][j];
        }
        
    }
    for (size_t i = 0; i < mat->size_i; i++)
    {
        free(mat->matrix[i]);
    }
    free(mat->matrix);
    mat->matrix=nmatrix;
    mat->size_i=rows;
    mat->size_j=cols;
}
double matrix_get_element(Matrix* mat, size_t rowIdx, size_t colIdx)
{
    if(!mat||rowIdx==0||colIdx==0||mat->size_i<rowIdx||mat->size_j<colIdx)return 0;

    return mat->matrix[rowIdx-1][colIdx-1];
}
void matrix_set_element(Matrix* mat, size_t rowIdx, size_t colIdx, double value)
{
    if(!mat||rowIdx==0||colIdx==0||mat->size_i<rowIdx||mat->size_j<colIdx)return;
    mat->matrix[rowIdx-1][colIdx-1]=value;
}
void matrix_set_identity(Matrix* mat)
{
    if(!mat)return;
    for (size_t i = 0; i < mat->size_i; i++)
    {
        for (size_t j = 0; j < mat->size_j; j++)
        {
            if(i==j)
            {
                mat->matrix[i][j]=1;
            }
            else
            {
                mat->matrix[i][j]=0;
            }
        }
        
    }
    
}
void matrix_set_zero(Matrix* mat)
{
    if(!mat)return;
    for (size_t i = 0; i < mat->size_i; i++)
    {
        for (size_t j = 0; j < mat->size_j; j++)
        {
            mat->matrix[i][j]=0;
        }
    }
}
void matrix_set_constants(Matrix* mat, double value)
{
    if(!mat)return;
    for (size_t i = 0; i < mat->size_i; i++)
    {
        for (size_t j = 0; j < mat->size_j; j++)
        {
            mat->matrix[i][j]=value;
        }
    }
}
void matrix_set_identity_resize(Matrix* mat, size_t size)
{
    if(!mat||size==0)return;
    dp* nmatrix = calloc(size,sizeof(dp));
    if(!nmatrix)return;
    for (size_t i = 0; i < size; i++)
    {
        nmatrix[i] = calloc(size,sizeof(d));
        if(!nmatrix[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(nmatrix[j]);
            }
            free(nmatrix);
            return;
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if(i==j)
            {
                nmatrix[i][j]=1;
            }
            else
            {
                nmatrix[i][j]=0;
            }
        }
        
    }
    for (size_t i = 0; i < mat->size_i; i++)
    {
        free(mat->matrix[i]);
    }
    free(mat->matrix);
    mat->matrix=nmatrix;
    mat->size_i=size;
    mat->size_j=size;
}
void matrix_set_zero_resize(Matrix* mat, size_t rows, size_t cols)
{
    if(!mat||rows==0||cols==0)return;
    dp* nmatrix = calloc(rows,sizeof(dp));
    if(!nmatrix)return;
    for (size_t i = 0; i < rows; i++)
    {
        nmatrix[i] = calloc(cols,sizeof(d));
        if(!nmatrix[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(nmatrix[j]);
            }
            free(nmatrix);
            return;
        }
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
           
            
            nmatrix[i][j]=0;
            
        }
        
    }
    for (size_t i = 0; i < mat->size_i; i++)
    {
        free(mat->matrix[i]);
    }
    free(mat->matrix);
    mat->matrix=nmatrix;
    mat->size_i=rows;
    mat->size_j=cols;
}
void matrix_set_constants_resize(Matrix* mat, size_t rows, size_t cols, double value)
{
    if(!mat||rows==0||cols==0)return;
    dp* nmatrix = calloc(rows,sizeof(dp));
    if(!nmatrix)return;
    for (size_t i = 0; i < rows; i++)
    {
        nmatrix[i] = calloc(cols,sizeof(d));
        if(!nmatrix[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(nmatrix[j]);
            }
            free(nmatrix);
            return;
        }
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
           
            
            nmatrix[i][j]=value;
            
        }
        
    }
    for (size_t i = 0; i < mat->size_i; i++)
    {
        free(mat->matrix[i]);
    }
    free(mat->matrix);
    mat->matrix=nmatrix;
    mat->size_i=rows;
    mat->size_j=cols;
}
Matrix* matrix_transpose(Matrix* mat)
{
    if(!mat)return NULL;

    Matrix* nmat = malloc(sizeof(Matrix));
    nmat->matrix = malloc(mat->size_j*sizeof(dp));
    if(!nmat->matrix)return NULL;
    for (size_t i = 0; i < mat->size_j; i++)
    {
        nmat->matrix[i] = malloc(mat->size_i*sizeof(d));
        if(!nmat->matrix[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(nmat->matrix[j]);
            }
            free(nmat->matrix);
            return NULL;
        }
    }
    for (size_t i = 0; i < mat->size_i; i++)
    {
        for (size_t j = 0; j < mat->size_j; j++)
        {
            nmat->matrix[j][i]=mat->matrix[i][j];
        }
        
    }
    nmat->size_i = mat->size_j;
    nmat->size_j=mat->size_i;
    return nmat;

}
static Matrix*matrix_copy(Matrix* mat)
{
    if(!mat)return NULL;

    Matrix* cmat = matrix_create(mat->size_i,mat->size_j);
    for (size_t i = 0; i < mat->size_i; i++)
    {
        for (size_t j = 0; j < mat->size_j; j++)
        {
            cmat->matrix[i][j]=mat->matrix[i][j];
        }
        
    }
    return cmat;
}
d matrix_determinant(Matrix* mat)
{
    if(!mat)return 0;
    Matrix* wmat=matrix_copy(mat);
    size_t size = wmat->size_i;
    int sign =1;
    d det =1;
    for (size_t i = 0; i < size-1; i++)//идём столбцам
    {
        size_t max_elem_pos=i;
        for (size_t j = i+1; j < size; j++)//ищем найб эл в столбце
        {
            if(fabs(wmat->matrix[j][i])>fabs(wmat->matrix[max_elem_pos][i]))
            {
                max_elem_pos=j;
            }
        }
        if(wmat->matrix[max_elem_pos][i]==0)
        {
            return 0;
        }
        if(max_elem_pos!=i)//свапаем на верх строку с наиб эл уч знак
        {
            dp temp = wmat->matrix[max_elem_pos];
            wmat->matrix[max_elem_pos]=wmat->matrix[i];
            wmat->matrix[i]=temp;
            sign = sign*-1;
        }
        for (size_t j = i+1; j < size; j++)//счит коэф вычита выч эл
        {
            d k_division = wmat->matrix[j][i]/wmat->matrix[i][i];
            for (size_t k = i; k < size; k++)
            {
                wmat->matrix[j][k]=wmat->matrix[j][k]-k_division*wmat->matrix[i][k];
            }
            
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        det=det*wmat->matrix[i][i];
        
    }
    matrix_destroy(wmat);
    return det*sign;
}
static d matrix_minor(Matrix* mat, size_t rowIdx, size_t colIdx)
{
    size_t size = mat->size_i-1;
    Matrix* mmat = matrix_create(size,size);
    size_t m_i=0;
    size_t m_j=0;
    for (size_t i = 0; i < size+1; i++)
    {
        if(i==rowIdx)
        {continue;}
        for (size_t j = 0; j < size+1; j++)
        {
            if(j==colIdx)
            {
                continue;
            }
            else
            {
                mmat->matrix[m_i][m_j] = mat->matrix[i][j];
                m_j++;
            }
        }
        m_i++;
        m_j=0;
    }
    d mdet=matrix_determinant(mmat);
    int sign;
    if((rowIdx+colIdx)%2==0)
    {
        return mdet;
    }
    else
    {
        return -mdet;
    }

}
Matrix* matrix_inverse(Matrix* mat)
{
    if(!mat)return NULL;

    size_t size = mat->size_i;
    d det = matrix_determinant(mat);
    if(det==0)return NULL;
    Matrix* imat = matrix_create(size,size);
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            imat->matrix[i][j]=matrix_minor(mat,i,j);
        }
    }
    Matrix* timat = matrix_transpose(imat);
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            timat->matrix[i][j]=timat->matrix[i][j]/det;
        }
    }
    return timat;
}
