// bee 2247 - Cofrinhos da Vo Vitoria
// Alonso Martins
// 05/06/2024
#include <stdio.h>

int main()
{
    int N, A, B, t = 1, dif;

    while (dif = 0, scanf("%d", &N), N && printf("Teste %d\n", t ++))
    {
        while (N -- && scanf("%d %d", &A, &B))
        {
            dif += A - B;
            printf("%d\n", dif);
        }
        printf("\n");
    }

    return 0;
}
