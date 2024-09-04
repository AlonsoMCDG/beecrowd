// bee 1944 - BRINDE FACE 2015
// Alonso Martins
// 04/09/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, len_painel = 0, premiados = 0;
    char painel[4 * 200 + 2], visitante[6] = {};

    scanf("%d", &N);

    while(N --)
    {
        // faz a leitura de tras pra frente das letras do participante
        for (i = 3; i >= 0; i --)
            scanf(" %c", &visitante[i]);

        // se o painel esta vazio, a organizacao insere "FACE"
        if (len_painel == 0)
        {
            strcpy(painel, "FACE");
            len_painel = 4;
        }

        // se a palavra formada pelas letras do participante eh igual
        // a palavra nas quatro ultimas posicoes do painel
        if (strcmp(&painel[len_painel - 4], visitante) == 0)
        {
            premiados ++;
            len_painel -= 4;
            painel[len_painel] = '\0';
        }
        else // senao, adiciona as letras do participante ao painel
        {
            for (i = 0; i < 4; i ++)
                painel[len_painel + i] = visitante[3 - i];
            len_painel += 4;
            painel[len_painel] = '\0';
        }
    }

    printf("%d\n", premiados);

    return 0;
}
