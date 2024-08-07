// bee 1367 - Ajude!
// Alonso Martins
// 07/08/2024
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N, T;
    char id, res[20];

    while (scanf("%d", &N), N)
    {
        int P = 0, S = 0, prev = -1;
        int erros[26] = {};

        while (N -- && scanf(" %c %d %s", &id, &T, res))
        {
            if (res[0] == 'c')
            {
                S ++;
                P += T + 20 * erros[id - 'A'];
            }
            else erros[id - 'A'] ++;
        }

        printf("%d %d\n", S, P);
    }

    return 0;
}
