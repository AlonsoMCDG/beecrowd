// bee 2785 - Piramide
// Alonso Martins
// 13/09/2024
#include <stdio.h>

#define MAX 100

int min(int a, int b) { return a < b ? a : b; }

int main()
{
    int N, i, j, k, sum, cont;
    int mat[MAX][MAX], soma[MAX][MAX] = {};

    scanf("%d", &N);

    for (i = 0; i < N; i ++)
        for (j = 0; j < N; j ++)
            scanf("%d", &mat[i][j]);

    for (i = 0; i < N; i ++)
    {
        sum = cont = k = 0;
        for (j = 0; j < N; j ++)
        {
            sum += mat[i][j];
            cont ++;

            if (cont == i + 1)
            {
                if (k > 0)
                    sum -= mat[i][k - 1];

                if (i > 0) 
                    soma[i][k] = sum + min(soma[i - 1][k], soma[i - 1][k + 1]);
                else
                    soma[i][k] = sum;

                cont --;
                k ++;
            }
        }
    }

    printf("%d\n", soma[N - 1][0]);

    return 0;
}
