// bee 2321 - Detectando Colisoes
// Alonso Martins
// 13/03/2024
#include <stdio.h>

int main()
{
    int x11, y11, x21, y21, x12, y12, x22, y22;

    scanf("%d %d %d %d", &x11, &y11, &x21, &y21);
    scanf("%d %d %d %d", &x12, &y12, &x22, &y22);

    printf("%d\n", !(x11 > x22 || y11 > y22 || x21 < x12 || y21 < y12));

    return 0;
}
