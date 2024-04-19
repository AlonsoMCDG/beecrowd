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
    int d;
    scanf("%d", &d);
    printf("%d ano(s)\n", divmod(&d, 365));
    printf("%d mes(es)\n", divmod(&d, 30));
    printf("%d dia(s)\n", d);
    return 0;
}
