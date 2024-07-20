// bee 2691 - O Matematico
// Alonso Martins
// 20/07/2024
#include <stdio.h>

void imprimir_produto(int a, int b)
{
    printf("%d x %d = %d", a, b, a * b);
}

int main()
{
    int T, N, M, i;

    scanf("%d", &T);

    while (T -- && scanf("%d%*c%d", &N, &M))
    {
        for (i = 5; i <= 10; i ++)
        {
            imprimir_produto(N, i);

            if (N != M) 
                printf(" && "), imprimir_produto(M, i);

            printf("\n");
        }
    }

    return 0;
}
