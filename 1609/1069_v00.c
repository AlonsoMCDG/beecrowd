// bee 1609 - Contando Carneirinhos
// Alonso Martins
// 28/08/2024
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int main()
{
    int T, N, i, ans;

    scanf("%d", &T);

    while (T -- && scanf("%d", &N))
    {
        int carneiros[N];

        for (i = 0; i < N; i ++)
            scanf("%d", &carneiros[i]);

        qsort(carneiros, N, sizeof(carneiros[0]), comp);

        ans = 1;
        for (i = 1; i < N; i ++)
            ans += carneiros[i] != carneiros[i - 1];

        printf("%d\n", ans);
    }

    return 0;
}
