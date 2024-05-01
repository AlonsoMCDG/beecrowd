// bee 1101 - Sequencia de Numeros e Soma
// Alonso Martins
// 01/05/2024
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int soma_sequencia(int start, int end)
{
    int i, soma;
    for (soma = 0, i = start; i <= end; soma += i, i ++)
        printf("%d ", i);
    return soma;
}

int main()
{
    int a, b;
    
    while (scanf("%d %d", &a, &b) && a > 0 && b > 0)
        printf("Sum=%d\n", soma_sequencia(min(a, b), max(a, b)));
    
    return 0;
}
