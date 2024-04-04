// bee 1471 - Megulho
// Alonso Martins
// 03/04/2024
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int main()
{
    int N, R, M, i, c;

    while (scanf("%d %d", &N, &R) != EOF)
    {
        c = 0;
        
        int r[MAX] = {0};

        for (i = 0; i < R; i ++)
        {
            scanf("%d", &M);
            r[M - 1]++;
            c++;
        }

        if (c == N)
        {
            printf("*\n");
            continue;
        }

        for (i = 0; i < N; i ++)
        {
            if (!r[i]) 
                printf("%d ", i + 1);
        }
        printf("\n");
    }
    return 0;
}
