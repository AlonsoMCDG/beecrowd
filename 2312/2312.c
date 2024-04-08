// bee 2312 - Quadro De Medalhas
// Alonso Martins
// 08/04/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[20];
    int O;
    int P;
    int B;
} Pais;

int comparar(const void *a, const void *b)
{
    Pais *A = (Pais *)a;
    Pais *B = (Pais *)b;
    int difO = B->O - A->O;
    int difP = B->P - A->P;
    int difB = B->B - A->B;
    int difN = strcmp(A->nome, B->nome);
    return difO ? difO : difP ? difP : difB ? difB : difN;
}
int main()
{
    int N, i;
    Pais *paises;

    scanf("%d", &N);

    paises = (Pais *)malloc(N * sizeof(Pais));

    for (i = 0; i < N; i ++)
    {
        scanf(" %s %d %d %d", &paises[i].nome, &paises[i].O, &paises[i].P, &paises[i].B);
    }
    
    qsort(paises, N, sizeof(Pais), comparar);
    
    for (i = 0; i < N; i ++)
    {
        printf("%s %d %d %d\n", paises[i].nome, paises[i].O, paises[i].P, paises[i].B);
    }//*/

    
    return 0;
}
