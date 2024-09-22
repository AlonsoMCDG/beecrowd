// bee 1867 - Maior Numero de Um Algarismo
// Alonso Martins
// 22/09/2024
#include <stdio.h>

int sum(char *x)
{
    int n = 0, ans = 0;

    while (*x)
        ans += *x ++ - '0';

    while (ans > 9)
    {
        n = 0;
        while (ans)
        {
            n += ans % 10;
            ans /= 10;
        }
        ans = n;
    }

    return ans;
}

int main()
{
    int a, b;
    char A[102] = {}, B[102] = {};

    while (scanf(" %s %s", A, B), A[0] != '0' || B[0] != '0')
    {
        a = sum(A);
        b = sum(B);
        printf("%d\n", a > b ? 1 : a < b ? 2 : 0);
    }

    return 0;
}
