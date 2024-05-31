// bee 1262 - Leitura Multipla
// Alonso Martins
// 30/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char registro[52];
    int P, i, r, w, sz, ans;

    while (scanf(" %s %d", registro, &P) != EOF)
    {
        for (ans = i = 0, sz = strlen(registro); i < sz; i += r + w)
        {
            r = strspn(&registro[i], "R");
            w = strspn(&registro[i], "W");
            ans += r / P + (r % P != 0);
            ans += w;
        }
        
        printf("%d\n", ans);
    }

    return 0;
}
