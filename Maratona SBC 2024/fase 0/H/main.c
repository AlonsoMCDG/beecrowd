// questão H - Homem do Saco e o Teorema de Bachgold
// Se contente com 3
// 25/05/2024
#include <stdio.h>

int ehPrimo(int x)
{
    int i;
    if (x == 2)
        return 1;
    if (x < 2 || x % 2 == 0)
        return 0;

    for (i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int T, N, x, y, r;

    scanf("%d", &T);

    while (r = 0, T -- && scanf("%d", &N))
    {
        x = N / 2;
        y = N / 2 + N % 2;

        while (x > 0 && (ehPrimo(x) || ehPrimo(y)))
            x --, y ++;
        
        if (x <= 0)
            printf("-1\n");
        else
            printf("%d %d\n", x, y);
    }
    
    return 0;
}
