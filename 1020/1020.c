// bee 1020 - Idade em Dias
// Alonso Martins
// 18/04/2024
#include <stdio.h>

int divmod(int *p, int m)
{
    int x = *p / m;
    *p %= m;
    return x;
}

int main()
{
    int d, m, a;
    scanf("%d", &d);
    a = divmod(&d, 365);
    m = divmod(&d, 30);
    printf("%d ano(s)\n", a);
    printf("%d mes(es)\n", m);
    printf("%d dia(s)\n", d);
    return 0;
}
