// bee 1273 - Justificador
// Alonso Martins
// 14/06/2024
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, i, flag = 0, maxLen;
    char palavras[50][52];

    while (scanf("%d", &N), N)
    {
        for (maxLen = i = 0; i < N; i ++)
        {
            scanf(" %s", palavras[i]);
            maxLen = (int)fmax(maxLen, strlen(palavras[i]));
        }

        if (flag ++) 
            printf("\n");
        for (i = 0; i < N; i ++)
            printf("%*s\n", maxLen, palavras[i]);
    }
    

    return 0;
}
