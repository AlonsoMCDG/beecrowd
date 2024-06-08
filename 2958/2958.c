// bee 2958 - O Role Bad Vibes
// Alonso Martins
// 08/06/2024
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    const char *A = (const char *)a, *B = (const char *)b;
    return B[0] - A[0];
}

int main()
{
    int N, M, i, j, k, cont = 0;
    scanf("%d %d%*c", &N, &M);
    char problemas[N * M][4];

    for (i = 0; i < N; i ++)
        for (j = 0; k = i * M + j, j < M; j ++)
        {
            scanf("%s", problemas[k]);
            if (problemas[k][1] == 'V')
                problemas[k][0] += 20, cont ++;
        }

    qsort(problemas, N * M, sizeof(problemas[0]), comp);

    for (i = 0; i < N * M; i ++)
    {
        if (problemas[i][1] == 'V') 
            problemas[i][0] -= 20;
        printf("%s\n", problemas[i]);
    }
    
    return 0;
}
