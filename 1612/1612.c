// bee 1612 - Formiguinha
// Alonso Martins
// 16/06/2024
#include <stdio.h>

int main()
{
    int T, N;

    scanf("%d", &T);

    while (T -- && scanf("%d", &N))
        printf("%d\n", (N + 1) / 2);

    return 0;
}
