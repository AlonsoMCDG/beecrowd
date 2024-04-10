// bee 2720 - Presentes Grandes
// Alonso Martins
// 08/04/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    int volume;
} Presente;
int compara_volume(const void *a, const void *b)
{
    Presente *A = (Presente *)a;
    Presente *B = (Presente *)b;
    int difV = B->volume - A->volume;
    int difId = A->id - B->id;
    return difV ? difV : difId;
}
int compara_id(const void *a, const void *b)
{
    Presente *A = (Presente *)a;
    Presente *B = (Presente *)b;
    return A->id - B->id;
}
int main()
{
    int T, N, K, I, H, W, L, i, j;
    Presente *presentes;

    scanf("%d", &T);

    while (T --)
    {
        scanf("%d %d", &N, &K);

        presentes = (Presente *)malloc(N * sizeof(Presente));
        
        for (i = 0; i < N; i ++)
        {
            scanf("%d %d %d %d", &presentes[i].id, &H, &W, &L);
            
            presentes[i].volume = H * W * L;
        }

        qsort(presentes, N, sizeof(Presente), compara_volume);

        qsort(presentes, K, sizeof(Presente), compara_id);

        for (i = 0; i < K; i ++)
            printf("%d%s", presentes[i].id, K - i - 1 ? " " : "\n");

        free(presentes);
    }
    return 0;
}
