#include <stdio.h>
#include <math.h>
int main()
{
    double a, b;
    double z;
    char c;
    scanf("%lf\n%c\n%lf", &a, &c, &b);
    switch (c)
    {
    case '+':
        z = a + b;
        break;
    case '-':
        z = a - b;
        break;
    case '*':
        z = a * b;
        break;
    case '/':
        z = a / b;
        break;
    }
    printf("%lf\n", z);
}