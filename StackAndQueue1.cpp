#include <bits/stdc++.h>

struct Stack
{
    int* base;
    int* top;
    int StackSize = 0;
    Stack()
    {
        base = new int[101];
        top = base;
    }
    void push(int a);
    bool pop();
};

void Stack::push(int a)
{
    *(this->top++) = a;
    this->StackSize++;
}

bool Stack::pop()
{
    if (this->top == this->base)
    {
        return false;
    }
    else
    {
        *(this->top--);
        this->StackSize--;
        return true;
    }
}

struct Queue
{
    int* base;
    int front;
    int rear;
    Queue()
    {
        base = new int[101];
        rear = 0;
        front = 0;
    }
    void push(int a);
    void pop();
};

void Queue::push(int a)
{
    this->base[this->rear] = a;
    this->rear = (this->rear + 1) % 100;
}
void Queue::pop()
{
    this->front = (this->front + 1) % 100;
}

int main()
{
    int num;
    std::string str;
    int a;
    Stack s{};
    Queue q{};
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::cin >> str;
        if (str == "in")
        {
            std::cin >> a;
            s.push(a);
            q.push(a);
        }
        if (str == "out")
        {
            s.pop();
            q.pop();
        }
    }
    int* p, * r;
    p = s.base;
    r = q.base + q.front;
    for (int i = 0; i < s.StackSize; i++)
    {
        if (i != s.StackSize - 1)
            std::cout << *p << " ";
        else
            std::cout << *p << std::endl;
        p++;
    }

    while (r != q.base + q.rear)
    {
        if (r != q.base + q.rear - 1)
            std::cout << *r << " ";
        else
            std::cout << *r;
        r++;
    }
    return 0;
}
