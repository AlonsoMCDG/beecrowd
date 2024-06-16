// bee 1643 - Converter Quilometros para Milhas
// Alonso Martins
// 15/06/2024
#include <stdio.h>

int main()
{
    int T, N, i, y;
    int fib[] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711 };

    scanf("%d", &T);

    while (T -- && scanf("%d", &N))
    {
        int bin[21] = {};
        y = 0;

        for (i = 20; N && i >= 0; i --)
            if (fib[i] <= N)
                N -= fib[i], bin[i] = 1;

        for (i = 0; i < 20; i ++)
            y += fib[i] * bin[i + 1];

        printf("%d\n", y);
    }
    
    return 0;
}
