// bee 2692 - Teclado Zoeiro
// Alonso Martins
// 17/08/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, M, i, j, sz;
    unsigned char tabela_ascii[256], a, b;
    char frase[1000]; // frase de entrada

    // preenche a tabela com os valores ascii
    for (i = 0; i < 256; i ++)
        tabela_ascii[i] = (char)i;

    // le a quantidade de trocas e quantidade de frases inseridas
    scanf("%d %d", &N, &M); 

    // faz as trocas das letras
    for (i = 0; i < N; i ++)
    {
        scanf(" %c %c", &a, &b);
        tabela_ascii[a] = b;
        tabela_ascii[b] = a;
    }

    for (j = 0; j < M; j ++)
    {
        scanf(" %[^\n]", frase);

        for (i = 0; frase[i] != '\0'; i ++)
            printf("%c", tabela_ascii[frase[i]]); // imprime o caractere trocado
        printf("\n");
    }

    return 0;
}
