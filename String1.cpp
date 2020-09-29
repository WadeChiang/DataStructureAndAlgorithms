#include <iostream>
#include <cstring>

using namespace std;

struct str {
    char ch[1 << 6 + 1]{ 0 };
    int length = 0;
    int getLength() {
        length = strlen(ch);
        return length;
    }
    int findPos(char c){
        int i=0;
        while(ch)
    }
};

str s1, s2;

int main() {
    cin >> s1.ch;
    cin >> s2.ch;
    bool flag;
    for (int i = 0; i < s1.getLength(); i++)
    {
        flag = true;
        for (int j = 0; j < s2.getLength(); j++)
        {
            if (s1.ch[i] == s2.ch[j])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            cout << s1.ch[i];
        }
    }
}