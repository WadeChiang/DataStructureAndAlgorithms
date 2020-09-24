#include <iostream>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define bool int
#define TRUE 1
#define FALSE 0

typedef struct
{
    int *elem;
    int length;
    int listsize;
} LinearList;

bool InitList(LinearList &L)
{
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int *));
    if (!L.elem)
        exit(0);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return TRUE;
}

bool ListInsert(LinearList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return FALSE;
    if (L.length >= L.listsize)
    {
        int *newbase = (int *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
        if (!newbase)
            exit(0);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    int *q, *p;
    q = &(L.elem[i - 1]);
    for (p = &(L.elem[L.length - 1]); p >= q; p--)
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;
    return TRUE;
}

bool ListDelete(LinearList &L, int i, int &e)
{
    if (i < 1 || i > L.length + 1)
        return FALSE;
    int *p = &(L.elem[i - 1]);
    e = *p;
    int *q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p;
    }
    --L.length;
    return TRUE;
}

int LocateElem(LinearList L, int e)
{
    int i = 1;
    int *p = L.elem;
    while (i <= L.length && *p++ != e)
    {
        i++;
    }
    if (i <= L.length)
        return i;
    else
        return 0;
}

void MergeList(LinearList La,LinearList Lb,LinearList &Lc){
    int *pa=La.elem;
    int *pb=Lb.elem;
    Lc.listsize=Lc.length=La.length+Lb.length;
    int *pc=Lc.elem=(int*)malloc(Lc.listsize*sizeof(int));
    if(!Lc.elem)
        exit(0);
    int *pa_last=La.elem+La.length-1;
    int *pb_last=Lb.elem+Lb.length-1;
    while(pa<=pa_last&&pb<=pb_last)
    {
        if(*pa<=*pb)
            *pc++=*pa++;
        else
        *pc++=*pb++;
    }
    while(pa<=pa_last)
        *pc++=*pa++;
    while(pb<=pb_last)
        *pc++=*pb++;
}

int main()
{
    return 0;
}