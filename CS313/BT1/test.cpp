#include <stdio.h>
int main()
{
    int a, b;
    printf("nhap so a:", a);
    scanf("%d", &a);
    printf("nhap so b:", b);
    scanf("%d", &b);
    for (int i = 1; i <= 1; i++)
    {
        printf("(a+b)^2:%d\n", a * a + 2 * a * b + b * b);
        printf("(a-b)^2:%d\n", a * a - 2 * a * b + b * b);
        printf("a^2-b^2:%d\n", (a - b) * 2 - (a + b) * 2);
        printf("(a+b)^3:%d\n", a * a * a + 3 * a * 2 * b + 3 * a * b * 2 + b * b * b);
        printf("(a-b)^3:%d\n", a * a * a - 3 * a * a * b + 3 * a * b * b - b * b * b);
        printf("a^3+b^3:%d\n", (a + b) * (a * a - 2 * a * b + b * b));
        printf("a^3-b^3:%d\n", (a - b) * (a * a + 2 * a * b + b * b));
    }
}