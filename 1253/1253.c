// bee 1253 - Cifra de Cesar
// Alonso Martins
// 07/07/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, L, i = 0, sz; scanf("%d", &N);
    char sentenca[52];

    while (printf(i ? "%s\n" : "", sentenca), N -- && scanf(" %s %d", sentenca, &L))
        for (i = 0, sz = strlen(sentenca); i < sz; i ++)
            sentenca[i] = ((26 + sentenca[i] - 'A' - L) % 26 + 'A');

    return 0;
}
