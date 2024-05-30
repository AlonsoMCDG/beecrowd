// bee 1607 - Avance as Letras
// Alonso Martins
// 30/05/2024
#include <stdio.h>
#include <string.h>

#define toc(x) (x - 'a' + 1)

int main()
{
    int T, i, ans, sz;
    char p1[10002], p2[10002];

    scanf("%d", &T);

    while (ans = 0, T -- && scanf(" %s %s", p1, p2) && (sz = strlen(p1)))
    {
        for (i = 0; i < sz; i ++)
            ans += (toc('z') - toc(p1[i]) + toc(p2[i])) % 26;
        
        printf("%d\n", ans);
    }

    return 0;
}
