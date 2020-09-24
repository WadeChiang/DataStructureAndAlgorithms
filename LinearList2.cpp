#include <iostream>
#include <stdlib.h>
#include <string>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

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
    return true;
}

bool ListInsert(LinearList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
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
    return true;
}

bool ListDelete(LinearList &L, int i, int &e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    int *p = &(L.elem[i - 1]);
    e = *p;
    int *q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p;
    }
    --L.length;
    return true;
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

int main()
{
    LinearList l;
    InitList(l);
    *(l.elem) = 1;
    l.length++;

    int num;
    std::cin >> num;
    std::string op;
    int op1, op2, pos;

    for (int i = 0; i < num; i++)
    {
        std::cin >> op;
        if (op == "add")
        {
            std::cin >> op1 >> op2;
            pos = LocateElem(l, op1) + 1;
            ListInsert(l, pos, op2);
        }
        if (op == "del")
        {
            std::cin >> op1;
            pos = LocateElem(l, op1)+1;
            ListDelete(l, pos, op2);
        }
    }

    for (int i = 0; i < l.length - 1; i++)
    {
        std::cout << l.elem[i] << ' ';
    }
    std::cout << l.elem[l.length - 1];
}