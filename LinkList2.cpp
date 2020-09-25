#include <iostream>
#include <stdlib.h>

typedef struct LNode
{
    int coe, exp;
    struct LNode * next;
} LNode, *LinkList;

bool ListInsert(LinkList &L, int i, int c, int e)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return false;
    LNode *s = (LinkList)malloc(sizeof(LNode));
    s->coe = c;
    s->exp = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList &L, int i, int &c, int &e)
{
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return false;
    LNode *q = p->next;
    p->next = q->next;
    e = q->exp;
    c = q->coe;
    free(q);
    return true;
}

void CreatList(LinkList &L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        std::cin >> (p->coe) >> (p->exp);
        p->next = L->next;
        L->next = p;
    }
    return ;
}

LinkList AddPoly(LinkList &la, LinkList &lb)
{
    LNode *qa = la->next;
    LNode *qb = lb->next;
    LinkList lc;
    int count{0};

    while (qa && qb)
    {
        count++;
        if (qa->exp > qb->exp)
        {
            ListInsert(lc,count,qa->coe,qa->exp);
            qa=qa->next;
        }
        if(qa->exp=qb->exp)
        {
            ListInsert(lc,count,qa->coe+qb->coe,qa->exp);
            qa=qa->next;
            qb=qb->next;
        }
        if (qa->exp < qb->exp)
        {
            ListInsert(lc,count,qb->coe,qb->exp);
            qb=qb->next;
        }
    }
    return lc;
}

int  ListLength(LinkList L){
    LNode *p=L->next;
    int i=0;
    while(p)
    {
        p=p->next;
        ++i;
    }
    return  i;
}

int main()
{
    int num;
    LinkList l1, l2;
    std::cin >> num;
    CreatList(l1, num);
    //std::cin >> num;
    //CreatList(l2, num);
    std::cout<<ListLength(l1);
}