// HOMEWORK: Funções e recursividade
// bee 1165 - Número Primo
// Alonso Martins
// 30/04/2024
#include <stdio.h>

int eh_primo(int n, int i)
{
    if (n < 2 || !(n % 2) && n - 2) return 0;
    if (n < 4 || i * i > n) return 1;
    if (!(n % i)) return 0;
    return eh_primo(n, i + 2);
}

int main()
{
    int t, n;
    
    scanf("%d", &t);

    while (t --)
    {
        scanf("%d", &n);
        printf("%d%s eh primo\n", n, eh_primo(n, 3) ? "" : " nao");
    }

    return 0;
}
