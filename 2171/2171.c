// bee 2171 - Dividindo com Fink
// Alonso Martins
// 05/06/2024
#include <stdio.h>

int main()
{
    int N, i, P, F;

    while (P = F = 0, i = 1, scanf("%d", &N), N)
    {
        while (F + i <= N) 
            F += i ++;
        P = N - F;
        
        printf("%d %d\n", F, P);
    }

    return 0;
}
