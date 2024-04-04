// bee 3428 - Estourando Baloes
// Alonso Martins
// 04/04/2024
#include <stdio.h>

int main() {
    int N, H, B[1000001] = {0}, F = 0, i;
    
    scanf("%d", &N);

    for(i = 0; i < N; i ++)
    {
        scanf("%d", &H);

        if (B[H])
        {
            B[H]--;
            B[H-1]++;
        }
        else
        {
            B[H-1]++;
            F ++;
        }
    }
    
    printf("%d\n", F);

    return 0;
}
