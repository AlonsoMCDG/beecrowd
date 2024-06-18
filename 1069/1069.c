// bee 1069 - Diamantes e Areia
// Alonso Martins
// 17/06/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, sz, ans, k;
    char s[1002];

    scanf("%d", &N);

    while (N -- && scanf(" %s", s))
    {
        for (i = ans = k = 0, sz = strlen(s); i < sz; i ++)
        {
            ans += (k && s[i] == '>');
            k += (k && s[i] == '>' ? -1 : s[i] == '<');
        }

        printf("%d\n", ans);
    }

    return 0;
}
