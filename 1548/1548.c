// bee 1548 - Fila do Recreio
// Alonso Martins
// 08/04/2024
#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int main()
{
    int T, M, N, i, notas[1000], fila[1000], ans;
    
    scanf("%d", &T);
    while (T --)
    {
        for (i = 0, scanf("%d", &M); i < M; i ++)
        {
            scanf("%d", &notas[i]);
            fila[i] = notas[i];
        }

        qsort(fila, M, sizeof(int), comparar);

        for (i = 0, ans = 0; i < M; i ++) 
            if (notas[i] == fila[i])
                ans ++;
        
        printf("%d\n", ans);
    }
    return 0;
}
