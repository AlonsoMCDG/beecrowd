// bee 1105 - Sub-prime
// Alonso Martins
// 27/03/2024
#include <stdio.h>
#include <stdlib.h>
#define MAX_B 20
int main(int argc, char *argv[]) {
    int B, N, D, C, V, i, R;
    scanf("%d %d", &B, &N);
    while (B + N) {
        int reservas[B], dividas[MAX_B] = {};

        for (i = 0; i < B; i++)
            scanf("%d", &reservas[i]);

        for (i = 0; i < N; i++) {
            scanf("%d %d %d", &D, &C, &V);
            reservas[C - 1] += V;
            dividas[D - 1] += V;
        }

        R = 'S';
        for (i = 0; i < B; i++) {
            if (reservas[i] < dividas[i]) {
                R = 'N';
                break;
            }
        }

        printf("%c\n", R);

        scanf("%d %d", &B, &N);
    }
    return 0;
}
