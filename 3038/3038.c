// bee 3038 - Carta de Natal Criptografada
// Alonso Martins
// 31/08/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char *tab = "                                 i u$ e'()o+,-./0123456789:;<=>?aABCDEFGHIJKLMNOPQRSTUVWXYZ[ ]^_`abcdefghijklmnopqrstuvwxyz{|}~ ";
    char F[1000];
    int i, sz;

    while (scanf(" %[^\n]", F) != EOF)
    {
        sz = strlen(F);
        for (i = 0; i < sz; i ++)
        {
            F[i] = tab[(int)F[i]];
        }
        printf("%s\n", F);
    }

    return 0;
}
