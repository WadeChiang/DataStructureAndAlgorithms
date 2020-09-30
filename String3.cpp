#include <bits/stdc++.h>

struct str
{
    char ch[1000000 + 1]{0};
    int next[1000000 + 1]{0};
    int length = 0;

    int getLength()
    {
        length = strlen(ch);
        return length;
    }

    int findFirstPos(char c)
    {
        int i = 0;
        while (this->ch[i] != c)
        {
            i++;
            if (i >= this->getLength())
            {
                i = this->getLength();
                break;
            }
        }
        return i;
    }

    void getNext(){
        int i=2;
        
    }
};