// HOMEWORK: Funções e recursividade
// bee 1101 - Sequência de Números e Soma
// Alonso Martins
// 28/04/2024
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int soma_sequencia(int start, int end)
{
    printf("%d ", start);
    if (start == end)
        return end;
    return start + soma_sequencia(start + 1, end);
}

int main()
{
    int a, b, sum;

    while (scanf("%d %d", &a, &b) && a > 0 && b > 0)
    {
        sum = soma_sequencia(min(a, b), max(a, b));
        printf("Sum=%d\n", sum);
    }
    return 0;
}
