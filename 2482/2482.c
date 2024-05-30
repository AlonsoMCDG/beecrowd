// bee 2482 - Etiquetas de Noel
// Alonso Martins
// 30/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, M, i, j;
    scanf("%d%*c", &N);
    typedef struct { char idioma[50], traducao[100]; } Traducao;
    Traducao traducoes[N];
    char nome[100], idioma[100];

    for (i = 0; i < N; i ++)
        scanf("%50[^\n]%*c %100[^\n]%*c", traducoes[i].idioma, traducoes[i].traducao);

    for (scanf("%d%*c", &M), i = 0; i < M && scanf("%100[^\n]%*c %100[^\n]%*c", nome, idioma); i ++)
        for (j = 0; j < N; j ++)
            if (!strcmp(traducoes[j].idioma, idioma))
                printf("%s\n%s\n\n", nome, traducoes[j].traducao);

    return 0;
}
