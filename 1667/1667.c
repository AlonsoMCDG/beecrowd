// bee 1667 - HTML
// Alonso Martins
// 03/01/2025
#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[82], *hr = "--------------------------------------------------------------------------------";
    int inicio_de_linha = 1, tamanho_da_linha = 0;

    while (scanf(" %s", &palavra) != EOF)
    {
        // quebra de linha
        if (strcmp(palavra, "<br>") == 0)
        {
            printf("\n");
            inicio_de_linha = 1;
            tamanho_da_linha = 0;
        }
        // linha de cabeçalho
        else if (strcmp(palavra, "<hr>") == 0)
        {
            if (!inicio_de_linha) printf("\n");
            printf("%s\n", hr);
            inicio_de_linha = 1;
            tamanho_da_linha = 0;
        }
        else
        {
            // se verdadeiro, a palavra não cabe nesta linha
            if (tamanho_da_linha + strlen(palavra) + !inicio_de_linha > 80)
            {
                // vai para a próxima linha
                printf("\n");
                inicio_de_linha = 1;
                tamanho_da_linha = 0;
            }

            // se já há alguma palavra nesta linha, insere um espaço
            if (!inicio_de_linha)
                printf(" ");

            // imprime a palavra
            printf("%s", palavra);

            // atualiza o tamanho da linha
            tamanho_da_linha += strlen(palavra) + !inicio_de_linha;
            inicio_de_linha = 0;
        }
    }
    printf("\n");

    return 0;
}
