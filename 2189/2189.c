// bee 2189 - Quermesse
// Alonso Martins
// 18/03/2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, N, i, *ent;

    t = 0;

    while (scanf("%d", &N) && N)
    {
        t += 1;

        ent = (int *)malloc(N * sizeof(int));
        for (i = 0; i < N; i ++)
            scanf("%d", &ent[i]);
        
        i = 0;

        while (ent[i] != i + 1)
            i++;

    	printf("Teste %d\n%d\n\n", t, i + 1);
    }
    return 0;
}
