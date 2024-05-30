// bee 2315 - Diferença Facil Entre Datas
// Alonso Martins
// 30/05/2024
#include <stdio.h>

int main()
{
    int dias[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int d1, m1, d2, m2;

    scanf("%d %d %d %d", &d1, &m1, &d2, &m2);

    printf("%d\n", dias[m2 - 1] + d2 - dias[m1 - 1] - d1);

    return 0;
}
