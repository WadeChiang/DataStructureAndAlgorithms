#include <bits/stdc++.h>

using namespace std;

struct Stack
{
    char *base;
    char *top;
    int StackSize = 0;
    Stack()
    {
        base = new char[101];
        top = base;
    }
    void push(char a);
    bool pop();
    char getTop();
};

void Stack::push(char a)
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
        this->top--;
        this->StackSize--;
        return true;
    }
}

char Stack::getTop()
{
    return *(this->top - 1);
}

int main()
{
    char c;
    Stack s{};
    bool flag = true;
    while (cin >> c)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        if (c == ')' || c == ']' || c == '}')
        {
            switch (c)
            {
            case ')':
                if (s.getTop() == '(')
                    s.pop();
                else
                    flag = false;
                break;
            case ']':
                if (s.getTop() == '[')
                    s.pop();
                else
                    flag = false;
                break;
            case '}':
                if (s.getTop() == '{')
                    s.pop();
                else
                    flag = false;
                break;
            default:
                break;
            }
        }
        if (!flag)
            {
                break;
            }
    }
    if(flag)
    {
        cout<<"YES";
    }
    if(!flag)
    {
        cout<<"NO";
    }
    return 0;
}