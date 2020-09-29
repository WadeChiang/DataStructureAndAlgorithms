#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct StackDouble
{
    double* base;
    double* top;
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
    char* base;
    char* top;
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

int cmp(char c1, char c2)
{
    int a1, a2;

    if ('+' == c1 || '-' == c1)
        a1 = 3;
    if ('*' == c1 || '/' == c1)
        a1 = 5;
    if ('^' == c1)
        a1 = 7;
    if ('s' == c1 || 'c' == c1)
        a1 = 8;
    if ('(' == c1)
        a1 = 1;
    if (')' == c1)
        a1 = 9;
    if ('#' == c1)
        a1 = 0;

    if ('+' == c2 || '-' == c2)
        a2 = 2;
    if ('*' == c2 || '/' == c2)
        a2 = 4;
    if ('^' == c2)
        a2 = 6;
    if ('s' == c2 || 'c' == c2)
        a2 = 8;
    if ('(' == c2)
        a2 = 9;
    if (')' == c2)
        a2 = 1;
    if ('#' == c2)
        a2 = 0;

    if (a1 > a2)
        return 1;
    if (a1 == a2)
    {
        return 0;
    }
    if (a1 < a2)
        return -1;
}

double calc(double numL, char op, double numR)
{
    if (op == 's')
    {
        return sin(numR);
    }
    if (op == 'c')
    {
        return cos(numR);
    }
    if (op == '+')
    {
        return (numL + numR);
    }
    if (op == '-')
    {
        return (numL - numR);
    }
    if (op == '*')
    {
        return (numL * numR);
    }
    if (op == '/')
    {
        return (numL / numR);
    }
    if (op == '^')
    {
        return pow(numL, numR);
    }
}

int main()
{

    string str;
    cin >> str;

    StackDouble OPND{};
    StackChar OPTR{};

    OPTR.push('#');

    char  op[11] = "+-*/^sc()#";
    char c = 0;
    int pa = -1;
    int pb = pa + 1;
    double numL, numR;

    while (true)
    {
        if (str[pb] <= 57 && str[pb] >= 48)
        {
            pa = str.find_first_of(op, pb);
            if (pa != string::npos)
            {
                if (pa != pb)
                {
                    string num(str, pb, pa - pb);
                    double d = atof(num.c_str());
                    OPND.push(d);
                }
            }
            pb = pa;
        }
        else
        {
            c = str[pb];
            switch (cmp(OPTR.getTop(), c))
            {
            case -1:
                OPTR.push(c);
                break;
            case 0:
                OPTR.pop();
                if (OPTR.getTop() == 's' || OPTR.getTop() == 'c')
                {
                    numR = OPND.getTop();
                    OPND.pop();
                    OPND.push(calc(0, OPTR.getTop(), numR));
                    OPTR.pop();
                }
                break;
            case 1:
                numR = OPND.getTop();
                OPND.pop();
                numL = OPND.getTop();
                OPND.pop();
                OPND.push(calc(numL, OPTR.getTop(), numR));
                OPTR.pop();
                pb--;
            }

            if ('s' == c || 'c' == c)
            {
                pb += 3;
            }
            else
            {
                pb++;
            }
            pa = pb;
            c = str[pb];
        }

        /*char* pp = OPTR.base;
        double* ppp = OPND.base;
        while (pp != OPTR.top)
        {
            std::cout << *pp << " ";
            pp++;              
        }
        std::cout << endl;
        while (ppp != OPND.top)
        {
            std::cout << *ppp << " ";
            ppp++;
        }
        std::cout << endl;*/
        if (OPTR.StackSize == 0)
            break;
    }
    cout.precision(3);
    cout << setiosflags(ios::fixed)<< OPND.getTop();
}