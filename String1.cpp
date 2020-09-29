#include <bits/stdc++.h>

using namespace std;

struct str {
    char ch[1<<10+1];
    int length=0;
    int getLength() {
        length = strlen(ch);
        return length;
    }
    void Delete(char c) {
        int i = 0;
        for (; ch[i] != c; i++);
        while (ch[i] != 0)
        {
            ch[i] = ch[i + 1];
            i++;
        }
    }

};

str s1, s2;

int main() {
    cin >> s1.ch;
    cin >> s2.ch;
    for (int i = 0; i < s2.getLength(); i++)
    {
        s1.Delete(s2.ch[i]);
    }
    cout << s1.ch;
}