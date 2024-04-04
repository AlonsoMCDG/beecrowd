// bee 3302 - Resposta Certa
// Alonso Martins
// 20/02/2024
#include <stdio.h>

int main()
{
    int N, resposta;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &resposta);
        printf("resposta %d: %d\n", i + 1, resposta);
    }
    return 0;
}
