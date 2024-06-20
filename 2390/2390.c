// bee 2390 - Escada Rolante
// Alonso Martins
// 20/06/2024
#include <stdio.h>

int main()
{
    int N, tempo = 10, t0, t1;

    scanf("%d %d", &N, &t0);

    while (N --- 1 && scanf("%d", &t1))
        tempo += 10 - (t1 - t0 < 10) * (t0 + 10 - t1), t0 = t1;

    printf("%d\n", tempo);

    return 0;
}
