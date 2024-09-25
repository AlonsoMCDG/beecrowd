// bee 2646 - Secret Chamber at Mount Rushmore
// Alonso Martins
// 25/09/2024
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ord(x) ((x) - 'a')
#define chr(x) ((x) + 'a')

int main()
{
    int N, M, i, j, k, t = 0;
    char A, B, p1[52], p2[52];
    bool ha_caminho[26][26] = {};
    bool aux_letras[26] = {};
    char letras[26] = {};
    char egdes[500][2];

    scanf("%d %d%*c", &N, &M);

    for (i = 0; i < 26; i ++)
        ha_caminho[i][i] = true;

    for (i = 0; i < N; i ++)
    {
        scanf("%c %c%*c", &A, &B);

        A = ord(A);
        B = ord(B);

        egdes[i][0] = chr(A);
        egdes[i][1] = chr(B);

        ha_caminho[A][B] = true;
        aux_letras[A] = true;
        aux_letras[B] = true;
    }

    for (i = 0; i < 26; i ++)
        if (aux_letras[i])
            letras[t ++] = i + 'a';

    for (k = 0; k < 26; k ++)
        for (i = 0; i < 26; i ++)
            for (j = 0; j < 26; j ++)
                if (ha_caminho[i][k] && ha_caminho[k][j])
                    ha_caminho[i][j] = true;

    for (k = 0; k < M; k ++)
    {
        scanf(" %s %s", p1, p2);
        int sz = strlen(p1);
        bool eh_possivel = sz == strlen(p2);

        if (eh_possivel)
        {
            for (i = 0; i < sz; i ++)
            {
                if (!ha_caminho[ord(p1[i])][ord(p2[i])])
                {
                    eh_possivel = false;
                    break;
                }
            }
        }

        printf("%s\n", eh_possivel ? "yes" : "no");
    }

    return 0;
}
