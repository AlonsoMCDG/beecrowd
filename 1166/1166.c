// bee 1166 - Torre de Hanoi, Novamente!
// Alonso Martins
// 21/05/2024
#include <stdio.h>
#include <string.h>
#include <math.h>

int res[50] = {};

int ehQuadrado(int x)
{
    int s = sqrt(x);
    return s * s == x;
}

void hanoi()
{
    int pinos[50]; memset(pinos, 0, 50 * sizeof(int));
    int i, j, n = 1, bola = 1;

    while (n <= 50)
    {
        i = n - 1;
        while (i != n)
        {
            if (pinos[i] == 0 || ehQuadrado(pinos[i] + bola))
                pinos[i] = bola ++, i = 0;
            else
                i ++;
        }

        res[n - 1] = bola - 1;
        n ++;
    }
}

int main()
{
    int T, N; scanf("%d", &T);

    hanoi();

    while (T -- && scanf("%d", &N))
        printf("%d\n", res[N - 1]);

    return 0;
}
