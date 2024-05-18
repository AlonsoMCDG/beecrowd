// bee 1768 - Arvore de Natal
// Alonso Martins
// 18/05/2024
#include <stdio.h>

void imprimirCaracteres(int l, int a)
{
    int i, j;
    for (i = 0; i <= a; i ++)
    {
        for (j = 0; j <= l + i; j ++)
            if (j < l - i || j > l + i)
                printf(" ");
            else
                printf("*");
        printf("\n");
    }
}

void imprimirArvore(int N)
{
    imprimirCaracteres(N / 2, N / 2); // imprime a arvore
    imprimirCaracteres(N / 2, 1); // imprime o caule
    printf("\n");
}

int main()
{
    int N;

    while (scanf("%d", &N) != EOF)
    {
        imprimirArvore(N);
    }

    return 0;
}
