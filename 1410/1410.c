// bee 1410 - Ele Esta Impedido!
// Alonso Martins
// 14/06/2024
#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return *(const int*)a - *(const int *)b;
}
int main()
{
    int A, D, i;
    char ans;
    int atk[11], def[11];

    while (scanf("%d %d", &A, &D), A && D)
    {
        for (i = 0; i < A; i ++)
            scanf("%d", &atk[i]);
        for (i = 0; i < D; i ++)
            scanf("%d", &def[i]);

        qsort(atk, A, sizeof(int), comparar);
        qsort(def, D, sizeof(int), comparar);

        for (i = 0, ans = 'N'; i < A && ans == 'N'; i ++)
            if (atk[i] < def[1])
                ans = 'Y';
            else if (atk[i] > def[1])
                break;

        printf("%c\n", ans);
    }

    return 0;
}
