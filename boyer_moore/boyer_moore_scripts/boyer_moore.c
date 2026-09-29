#include "boyer_moore.h"
#include <stdlib.h>
#include <limits.h>
#include "sort_comparators.h"
int boyer_moore(char* haystack, char* needle)
{
    if(!haystack||!needle)
    {
        return-1;
    }
    //длины строк
    //длина текста и образца
    int len_hs=0, len_n=0;
    int hs_i=0,n_i=0;
    while (haystack[hs_i]!='\0')
    {
        len_hs++;
        hs_i++;
    }
    while (needle[n_i]!='\0')
    {
        len_n++;
        n_i++;
    }
    if(len_hs<len_n|| len_hs==0)
    {
        return -1;
    }
    
    int* bc_t = build_bad_char_table(needle, len_n);
    int* gs_t=build_good_suffix_table(needle, len_n);
    //нчальный сдвиг откуда сопост наша игла
    int hs_offset = 0;
    while (hs_offset<=len_hs-len_n)
    {

        int n_offset =len_n-1;//начинаем с права на лево
        while (n_offset>=0&&needle[n_offset]==haystack[hs_offset+n_offset])
        {
            n_offset--;
        }
        if(n_offset<0)
        {
            //нашли
            free(bc_t);
            free(gs_t);
            return hs_offset;
        }
        else
        {
            //не нашли
            int index = haystack[hs_offset+n_offset]; //олуч симвл
            int bad_offset = bc_t[index]-(len_n-1-n_offset); //берём сдвиг из бс таблицы и хорошей
            int good_offset=gs_t[n_offset];
            int offset;
            if(cmp_int(&bad_offset,&good_offset)==1) //смотриим на сколько сдвиг
            {
                offset=bad_offset;
            }
            else
            {
                offset=good_offset;
            }
            hs_offset=hs_offset+offset;
        }
    }
    free(bc_t);
    free(gs_t);
    return -1;
}

int* build_bad_char_table(char* needle,int len_n)
{
    //заполнил массив сдвигов на m
    int* bad_char_table = malloc(CHAR_MAX*sizeof(int));
    if(!bad_char_table) return NULL;
    for (int i=0;i<CHAR_MAX;i++)
    {
        bad_char_table[i]=len_n;
    }
    //заполняем по алгаритму
    for(int i=0;i<len_n;i++)
    {
        int cur_char = needle[i];
        bad_char_table[cur_char] = len_n-1-i;
    }
    return bad_char_table;
}

int* build_good_suffix_table(char* needle,int len_n)
{
    int* offset = malloc(sizeof(int)*len_n); //наши сдвиги
    if(!offset) return NULL;
    for(int i=0;i<len_n;i++)
    {
        offset[i]=len_n;
    }
    int* border = calloc(len_n+1,sizeof(int)); //на 1 граница префикса длиной i
    //хранит длины границ самого большого суфикса
    if(!border) return NULL;

    int i=len_n;
    int j=i+1;//для начала с самого дальнего
    border[i]=j; 

    while (i>0) //проход по всем постфиксам
    {
        //пока текущий кандидат j не подходит как граница откатываться к меньшему кандидату
        while (j<=len_n&&needle[i-1]!=needle[j-1])//1усл ещё в слове 2 усл сама проверка кандидата 
            //i-1 последний символ в префиксе j-1 это конец другого префикс длиной j
            
        {
            if(offset[j-1]==len_n)//установлен ли уже сдвиг для позиции
            {
                offset[j-1]=j-i;
            }
            j=border[j];//кандидат j не подошёл пробуем меньший кандида который вложен в текущий
        }
        i--;
        j--;
        border[i]=j;
        
    }
    //offset заполнялся частично только для позиций где j откатывался во внутреннем while
    j=border[0];
    for(i=0;i<len_n-1;i++) //заполняем офсет по алга
    {
        if(offset[i]==len_n)
        {
            offset[i]=j;
        }
        if(i==j)
        {
            j = border[j];
        }
    }
    free(border);
    return offset;
}
