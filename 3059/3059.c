// bee 3059 - Pares de Numeros
// Alonso Martins
// 30/05/2024
#include <stdio.h>

int main()
{
    int N, I, F, i, j, ans;
    scanf("%d %d %d", &N, &I, &F);
    int v[N];

    for (i = ans = 0; scanf("%d", &v[i]), i < N; i ++)
        for (j = 0; j < i; j ++)
            ans += (v[j] + v[i] >= I && v[j] + v[i] <= F);

    printf("%d\n", ans);

    return 0;
}
