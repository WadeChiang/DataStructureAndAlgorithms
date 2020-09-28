#include <bits/stdc++.h>

using namespace std;

struct StackDouble
{
    double *base;
    double *top;
    int StackSize = 0;
    StackDouble()
    {
        base = new double[1000];
        top = base;
    }
    void push(double a)
    {
        *(this->top++) = a;
        this->StackSize++;
    }
    bool pop()
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
    double getTop()
    {
        return *(this->top - 1);
    }
};

struct StackChar
{
    char *base;
    char *top;
    int StackSize = 0;
    StackChar()
    {
        base = new char[1000];
        top = base;
    }
    void push(char a)
    {
        *(this->top++) = a;
        this->StackSize++;
    }
    bool pop()
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
    char getTop()
    {
        return *(this->top - 1);
    }
};

int main()
{

    string str;
    cin >> str;

    StackDouble OPND{};
    StackChar OPTR{};

    char *op = "+-*/sc()#";
    int a = -1;
    while (true)
    {
        int b=a+1;
        a = str.find_first_of(op,a+1);
        if (a == string::npos)
            break;
        if (a != b)
        {
            string num(str, b, a - b);
            double d = atof(num.c_str());
            OPND.push(d);
        }
    }
}