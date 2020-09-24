#include <iostream>
#include <stdlib.h>

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
    L.elem[i-1]=e;
    ++L.length;
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

int main() {
    int toLocate, insert;
    LinearList l;
    InitList(l);
    std::cin >> toLocate;
    int i = 1;
    while (std::cin >> insert) {
        ListInsert(l, i, insert);
        i++;
    }
    int locate = LocateElem(l, toLocate);
    std::cout << locate << std::endl;
    std::cout << l.length;
    return 0;
}