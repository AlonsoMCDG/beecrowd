// bee 3165 - Primos Gemeos
// Alonso Martins
// 06/04/2024
#include <stdio.h>
#include <string.h>

int ehPrimo(int n)
{
    int i;
    for (i = 2; i * i <= n; i ++)
        if (!(n % i)) 
          return 0;
    return n > 1;
}
int main()
{
    int N, p1, p2;
    
    scanf("%d", &N);
    
    N += N % 2 - 1;
    
    while (N > 4)
    {
        if (ehPrimo(N) && ehPrimo(N - 2))
        {
            printf("%d %d\n", N - 2, N);
            return 0;
        }
        
        N -= 2;
    }
    
    return 0;
}
