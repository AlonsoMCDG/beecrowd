// bee 1235 - De Dentro para Fora
// Alonso Martins
// 28/04/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, size, i;
    char impressao[102];
    char esq[51], dir[51];

    scanf("%d%*c", &N);
    
    while (N--)
    {
        fgets(impressao, sizeof(impressao), stdin);
        size = strlen(impressao);
        impressao[-- size] = '\0';

        for (i = 0; i < size / 2; i ++)
        {
            esq[i] = impressao[size / 2 - 1 - i];
            dir[i] = impressao[size - 1 - i];
        }
        
        esq[i] = dir[i] = '\0';

        printf("%s%s\n", esq, dir);
    }
    return 0;
}
