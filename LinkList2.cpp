#include <iostream>
#include <stdlib.h>

typedef struct LNode
{
    int coe, exp;
    struct LNode* next;
} LNode, * LinkList;

bool ListInsert(LinkList& L, int i, int c, int e)
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
    LNode* s = (LinkList)malloc(sizeof(LNode));
    s->coe = c;
    s->exp = e;
    s->next = p->next;
    p->next = s;
    L->coe++;
    return true;
}

bool ListDelete(LinkList& L, int i, int& c, int& e)
{
    LNode* p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return false;
    LNode* q = p->next;
    p->next = q->next;
    e = q->exp;
    c = q->coe;
    free(q);
    return true;
}

void CreatList(LinkList& L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    L->coe = 0;//头结点的coe用于存储链表的长度
    LNode* p, * q;
    q = L;
    for (int i = 0; i < n; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));
        std::cin >> (p->coe) >> (p->exp);
        p->next = NULL;
        q->next = p;
        q = p;
        L->coe++;
    }
    return;
}

void AddPoly(LinkList& la, LinkList& lb)
{
    LNode* pa = la->next;
    LNode* pb = lb->next;
    while (pa != NULL && pb != NULL)
    {
        LNode* temp = (LNode*)malloc(sizeof(LNode));
        temp->next = NULL;
        if (pa->exp > pb->exp)
        {
            pa = pa->next;
            continue;
        }
        if (pa->exp == pb->exp)
        {
            pa->coe += pb->coe;
            pb = pb->next;
            if (pa != NULL && pa->coe == 0)
            {
                temp = la;
                while (temp->next != pa)
                {
                    temp = temp->next;
                }
                temp->next = pa->next;
                pa = pa->next;
                la->coe--;
            }
            continue;
        }
        if (pa->exp < pb->exp)
        {
            temp = la;
            while (temp->next != pa)
            {
                temp = temp->next;
            }
            temp->next = pb;
            pb = pb->next;
            (temp->next)->next = pa;
            la->coe++;
            continue;
        }
    }
    while (pb)
    {
        if (pa == NULL)
        {
            LNode* temp = la;
            while (temp->next != pa)
            {
                temp = temp->next;
            }
            pa = temp;
        }

        pa->next = pb;
        pa = pb;
        pb = pb->next;
        la->coe++;
    }
}

void CopyList(LinkList La, LinkList& Lb)
{
    Lb = (LinkList)malloc(sizeof(LNode));;
    Lb->next = NULL;
    Lb->coe = La->coe;
    LNode* p, * q, * r;
    q = Lb;
    r = La->next;
    for (int i = 0; i < Lb->coe; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));
        p->coe = r->coe;
        p->exp = r->exp;
        p->next = NULL;
        q->next = p;
        q = p;
        r = r->next;
    }
    return;
}

int main()
{
    int num, coe, exp;
    LinkList l1 = NULL, l2 = NULL;

    std::cin >> num;
    CreatList(l1, num);
    std::cin >> num;
    CreatList(l2, num);

    LNode* p = l2->next;
    LinkList l3, LFinal = (LinkList)malloc(sizeof(LNode));
    for (int i = 0; i < l2->coe; i++)
    {
        CopyList(l1, l3);
        LNode* q = l3->next;
        for (int j = 0; j < l3->coe; j++)
        {
            q->exp += p->exp;
            q->coe *= p->coe;
            q = q->next;
        }
        p = p->next;
        if (i == 0)
            CopyList(l3, LFinal);
        else
            AddPoly(LFinal, l3);
    }

    std::cout << LFinal->coe << std::endl;

    p = LFinal->next;
    for (int i = 0; i < LFinal->coe; i++)
    {
        if (i == LFinal->coe - 1)
        {
            std::cout << p->coe << " " << p->exp;
        }
        else
            std::cout << p->coe << " " << p->exp << std::endl;
        p = p->next;
    }
    return 0;
}