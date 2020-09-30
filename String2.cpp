#include <iostream>
#include <cstring>

using namespace std;

struct str
{
    char ch[1 << 10 + 1]{0};
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
    void insert(str s, int pos)
    {
        pos += 1;
        for (int i = 0; i < s.getLength(); i++)
        {
            for (int j = this->getLength() - 1; j >= pos; j--)
            {
                this->ch[j + 1] = this->ch[j];
            }
            this->ch[pos] = s.ch[i];
            pos++;
            this->length++;
        }
    }
};

str s1, s2;

int main()
{
    char x;
    cin >> s1.ch;
    cin >> s2.ch;
    cin >> x;
    int pos = s1.findFirstPos(x);
    if (pos < s1.getLength())
    {
        s1.insert(s2, pos);
        cout << s1.ch;
    }
    else
        cout << s1.ch << s2.ch;
    return 0;
}