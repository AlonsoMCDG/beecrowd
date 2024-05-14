// bee 2381 - Lista de Chamada
// Alonso Martins
// 14/05/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

int main()
{
    int N, K, i;

    scanf("%d %d%*c", &N, &K);

    char alunos[N][22];

    while (i < N) scanf("%s", alunos[i ++]);

    qsort(alunos, N, sizeof(alunos[0]), comparar);

    printf("%s\n", alunos[K - 1]);

    return 0;
}
