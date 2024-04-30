// bee 1165 - Número Primo
// Alonso Martins
// 28/04/2024
#include <stdio.h>

int eh_primo(int n)
{
    int i = 3;

    if (n < 2 || !(n % 2) && n - 2) return 0;
    if (n < 4) return 1;
    
    for (; i * i <= n; i += 2)
        if (!(n % i)) 
            return 0;
    return 1;
}

int main()
{
    int t, n;
    
    scanf("%d", &t);

    while (t --)
    {
        scanf("%d", &n);
        printf("%d%s eh primo\n", n, eh_primo(n) ? "" : " nao");
    }

    return 0;
}
