// bee 1062 - Trilhos
// Alonso Martins
// 11/04/2024
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct
{
    int vetor[MAX];
    int topo;
} Pilha;
void estacionar(Pilha *est, int v)
{
    est->vetor[++est->topo] = v;
}
void liberar_vagao(Pilha *est)
{
    est->topo --;
}
int main()
{
    int N, i = 0, pistaA = 1, pistaB;
    char *ans = "Yes";
    Pilha *estacao = (Pilha *)malloc(sizeof(Pilha));

    while (scanf("%d", &N) && N)
    {
        estacao->topo = -1;
        while (scanf("%d", &pistaB))
        {
            if (i ++ == N) {
                printf("%s\n", ans);
                i = 1;
                estacao->topo = -1;
                pistaA = 1;
                ans = "Yes";
            }
            if (!pistaB){
                i = 0;
                printf("\n");
                break;
            }
            
            while (pistaA < pistaB){
                estacionar(estacao, pistaA);
                pistaA ++;
            }
            
            if (pistaA == pistaB){
                pistaA ++;
                continue;
            }

            if (estacao->vetor[estacao->topo] == pistaB){
                liberar_vagao(estacao);
            }else{
                ans = "No";
                for (; i < N; i ++)
                    scanf("%d", &pistaB);
            }
        } 
    }  

    return 0;
}
