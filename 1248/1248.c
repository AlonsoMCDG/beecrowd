// bee 1248 - Plano de Dieta
// Alonso Martins
// 02/05/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

void reduzir(char dieta[28])
{
    int i = 0, j = 0, s = strlen(dieta);
    
    for (i = 0; i < s; i ++)
    {
        if (dieta[i] == ' ')
        {
            if (j == 0) j = i + 1;
            for (; dieta[j] == ' ' && dieta[j] != '\0'; j ++);
            if (dieta[j] == '\0')
            {
                dieta[i] = '\0';
                return;
            } else {
                dieta[i] = dieta[j];
                dieta[j] = ' ';
            }
        }
    }
}

int comer(char dieta[28], char refeicao[28])
{
    int i, j, sz1 = strlen(dieta), sz2 = strlen(refeicao);

    if (sz2 > sz1) return 1;
    
    for (i = 0; i < sz2; i ++)
    {
        for (j = 0; j < sz1; j ++)
        {
            if (dieta[j] > refeicao[i] || j == sz1 - 1 && dieta[j] != refeicao[i])
                return 1;
            
            if (dieta[j] == refeicao[i])
            {
                dieta[j] = ' ';
                break;
            }
        }
    }

    reduzir(dieta);
    return 0;
}

void zerar(int v[26])
{
    int i;
    for (i = 0; i < 26; i ++)
        v[i] = 0;
}

int main()
{
    int N, i, j;
    scanf("%d%*c", &N);

    for (i = 0; i < N; i ++)
    {
        char dieta[28], cafe[28], mittag[28];
        int cheater = 0;
        
        fgets(dieta, sizeof(dieta), stdin);
        fgets(cafe, sizeof(cafe), stdin);
        fgets(mittag, sizeof(mittag), stdin);
        dieta[strlen(dieta) - 1] = cafe[strlen(cafe) - 1] = '\0';
        if (mittag[strlen(mittag) - 1] == '\n') mittag[strlen(mittag) - 1] = '\0';
        
        qsort(dieta, strlen(dieta), sizeof(dieta[0]), comparar);
        qsort(cafe, strlen(cafe), sizeof(cafe[0]), comparar);
        qsort(mittag, strlen(mittag), sizeof(mittag[0]), comparar);

        cheater = comer(dieta, cafe);
        if (!cheater) 
            cheater = comer(dieta, mittag);

        printf("%s\n", cheater ? "CHEATER" : dieta);
    }

    return 0;
}
