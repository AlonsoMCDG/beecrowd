// bee 1342 - Dado
// Alonso Martins
// 25/09/2024
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int P, S, N, i, T, D1, D2;

    while (scanf("%d %d", &P, &S), P && S)
    {
        bool is_trap[10020] = {};

        for (i = 0; i < 3; i ++)
        {
            scanf("%d", &T);
            is_trap[T] = true;
        }

        int players[10] = {};
        int vez = 0;
        bool esta_preso[10] = {};

        scanf("%d", &N);
        for (i = 0; i < N; i ++)
        {
            
            while (esta_preso[vez])
            {
                esta_preso[vez] = 0;
                vez = (vez + 1) % P;
            }

            scanf("%d %d", &D1, &D2);

            players[vez] += D1 + D2;

            if (players[vez] > S)
                break;

            esta_preso[vez] = is_trap[players[vez]];
            vez = (vez + 1) % P;
        }

        printf("%d\n", vez + 1);
    }
    

    return 0;
}
