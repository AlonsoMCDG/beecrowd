// bee 3049 - Nota Cortada
// Alonso Martins
// 11/06/2024
#include <stdio.h>

int sinal(int x)
{
    return x < 0 ? -1 : !!x;
}

int main()
{
    int B, T, ans[] = {2, 0, 1};

    scanf("%d %d", &B, &T);

    printf("%d\n", ans[1 + sinal((B - (160 - T)))]);

    return 0;
}
