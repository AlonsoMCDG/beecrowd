// bee 1337 - Poker do Rei
// Alonso Martins
// 13/09/2024
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int categorias[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int A, B, C;
    int carta_rei; // carta mais frequente na mao
    int carta;
    bool par, trio;

    while (scanf("%d %d %d", &A, &B, &C), A)
    {
        par = trio = false;
        int mao[14] = {};

        mao[A] ++, mao[B] ++, mao[C] ++;
        par = (mao[A] == 2) || (mao[B] == 2) || (mao[C] == 2); // se a mao eh par
        trio = (mao[A] == 3) || (mao[B] == 3) || (mao[C] == 3); // se a mao eh trio
        carta_rei = (mao[A] > 1 ? A : mao[B] > 1 ? B : C); // carta mais frequente na mao

        if (trio)
        {
            if (carta_rei == 13)
                printf("*\n");
            else
                printf("%d %d %d\n", carta_rei + 1, carta_rei + 1, carta_rei + 1);
        }
        else
        {
            carta = A + B + C - 2 * carta_rei; // recebe a carta sem correspondente

            if (!par)
                printf("1 1 2\n");
            else if ((carta == 12 && carta_rei == 13))
                printf("1 1 1\n");
            else // eh par
            {
                if (carta > carta_rei)
                {
                    if (carta == 13)
                        printf("1 %d %d\n", carta_rei + 1, carta_rei + 1);
                    else // carta_rei + 1 <= carta
                        printf("%d %d %d\n", carta_rei, carta_rei, carta + 1);
                }
                else // carta < carta_rei
                {
                    if (carta == carta_rei - 1)
                        printf("%d %d %d\n", carta_rei, carta_rei, carta + 2);
                    else // carta < carta_rei - 1
                        printf("%d %d %d\n", carta + 1, carta_rei, carta_rei);
                }
            }
        }
    }

    return 0;
}
