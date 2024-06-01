// bee 1997 - Branco e Preto
// Alonso Martins
// 01/06/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int ans, i, sz;
    char S[502], T[502];

    while (scanf(" %s %s", S, T), S[0] != '*')
    {
        for (sz = strlen(S), ans = i = 0; i < sz; i ++)
        {
            if (S[i] != T[i])
            {
                while (i < sz && S[i] != T[i])
                    i ++;
                ans ++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
