// bee 2286 - Par ou Impar
// Alonso Martins
// 14/06/2024
#include <stdio.h>

int main()
{
    int N, p, q, t = 0;

    while (scanf("%d", &N), t ++, N)
    {
        char jog[2][12];
        scanf(" %s %s", jog[0], jog[1]);

        printf("Teste %d\n", t);

        while (N -- && scanf("%d %d", &p, &q))
            printf("%s\n", jog[(p + q) % 2]);

        printf("\n");
    }

    return 0;
}
