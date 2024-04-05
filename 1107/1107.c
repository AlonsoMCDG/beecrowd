// bee 1107 - Escultura a Laser
// Alonso Martins
// 04/04/2024
#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, C, i, ans;

    while (scanf("%d %d", &A, &C) && (A + C))
    {
        int alturas[10000];
        scanf("%d", &alturas[0]);
        ans = A - alturas[0];

        for (i = 1; i < C; i ++)
        {
            scanf("%d", &alturas[i]);

            if (alturas[i] < alturas[i-1])
                ans += alturas[i-1] - alturas[i];
        }

        printf("%d\n", ans);
    }
    return 0;
}
