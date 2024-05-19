// bee 2473 - Loteria
// Alonso Martins
// 18/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, acertos = 0, cartela[99]; memset(cartela, 0, 99 * sizeof(int));
    char *resultado[] = {"azar", "azar", "azar", "terno", "quadra", "quina", "sena"};

    for (i = 0; i < 6; i ++)
        scanf("%d", &n), cartela[n - 1] = 1;

    for (i = 0; i < 6; i ++)
        scanf("%d", &n), acertos += cartela[n - 1];
    
    printf("%s\n", resultado[acertos]);
    
    return 0;
}
