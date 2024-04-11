// bee 1086 - O Salao do Clube
// Alonso Martins
// 11/04/2024
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10001

typedef struct
{
    int *estoque;
    int larguraTabuas;
} Estoque;

double preencher_piso(Estoque *e, int largura, int altura)
{
    int i;
    int tabuas1 = e->estoque[altura];
    int tabuas2 = 0;
    double r = INFINITY;
    int L = (100 * largura) / e->larguraTabuas;
    
    if ((100 * largura) % e->larguraTabuas)
        return r;
    
    for (i = 1; i <= altura / 2; i ++)
    {
        if (e->estoque[i] && e->estoque[altura - i])
        {
            if (i != altura - i)
                tabuas2 += fmin(e->estoque[i], e->estoque[altura - i]);
            else if (e->estoque[i] >= 2)
                tabuas2 += e->estoque[i] / 2;
        }
    }
    
    int t1 = fmin(tabuas1, L);
    int t2 = fmin(tabuas2, (L - t1));
    
    if (t1 + t2 == L)
        r = t1 + 2 * t2;
    
    return r;
}

void preencher_estoque(Estoque *e, int K)
{
    int i, X;
    for (i = 0; i < K; i ++)
    {
        scanf("%d", &X);
        e->estoque[X]++;
    }
}

void esvaziar_estoque(Estoque *e)
{
    e->estoque = (int *)calloc(MAX, sizeof(int));
}

int main()
{
    int M, N, K, i;
    double ansM, ansN, ans;
    Estoque *e = (Estoque *)malloc(sizeof(Estoque));
    
    while (scanf("%d %d", &M, &N) && M + N)
    {
        scanf("%d %d", &(e->larguraTabuas), &K);

        esvaziar_estoque(e);
        preencher_estoque(e, K);

        ansM = preencher_piso(e, N, M);
        ansN = preencher_piso(e, M, N);
        
        ans = fmin(ansM, ansN);
        
        printf(ans == INFINITY ? "impossivel\n" : "%.0lf\n", ans);
    }

    return 0;
}
