#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int getValue(char c) {
    int value=0;
    if (c == 'M')
    {
        value = 1000;
    }
    if (c == 'D')
    {
        value = 500;
    }
    if (c == 'C')
    {
        value = 100;
    }
    if (c == 'L')
    {
        value = 50;
    }
    if (c == 'X')
    {
        value = 10;
    }
    if (c == 'V')
    {
        value = 5;
    }
    if (c == 'I')
    {
        value = 1;
    }
    return value;
}

int cmp(char a, char b)
{
    int ia, ib;

    ia = getValue(a);

    ib = getValue(b);

    if (ia > ib || ia == ib)
    {
        return 1;
    }
    if (ia < ib)
    {
        return 0;
    }
}




struct str
{
    char ch[1000]{ 0 };
    int length = 0;

    int getLength()
    {
        length = strlen(ch);
        return length;
    }
    int toInt() {
        int value, temp;
        value = 0;
        for (int i = 0; i < getLength()-1; i++)
        {
            if (cmp(ch[i], ch[i+1]) == 1)
            {
                value += getValue(ch[i]);
            }
            else
            {
                value += getValue(ch[i]);
                temp = value % getValue(ch[i+1]);
                value = value - 2*temp;
            }
        }
        value += getValue(ch[getLength() - 1]);
        return value;
    }
};


str s;

int main() {
    cin >> s.ch;
    int val = s.toInt();
    cout << val;
}