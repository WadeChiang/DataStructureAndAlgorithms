#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

struct str
{
    char ch[2000000 + 1]{ 0 };
    int pi[2000000 + 1]{ 0 };
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

    void getPi(int length)
    {
        int i = 1;
        for (; i < length; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && ch[i] != ch[j])
            {
                j = pi[j - 1];
            }
            if (ch[i] == ch[j])
            {
                j++;
            }
            pi[i] = j;
        }
    }
};

str s1, s2;

int main() {
    cin >> s1.ch;
    cin >> s2.ch;

    int subStringLength = s2.getLength();
    s2.ch[subStringLength] = '#';
    int textLength = s1.getLength();
    strncpy(s2.ch + subStringLength + 1, s1.ch, textLength);

    s2.getPi(subStringLength + textLength + 1);

    for (int i = subStringLength + 1; i < subStringLength + textLength + 1; i++)
    {
        if (s2.pi[i] == subStringLength)
        {
            cout << i - 2 * subStringLength + 1 << endl;
        }
    }

    return 0;
}