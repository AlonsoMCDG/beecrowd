// bee 1444 - Corrida dos Marrecos
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N;

    while (scanf("%d", &N), N)
    {
        int corridas = 0;

        while (N > 1)
        {
            corridas += (N = (int)ceil(N / 3.0));
        }

        printf("%d\n", corridas);
    }

    return 0;
}
