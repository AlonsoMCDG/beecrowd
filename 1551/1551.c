// bee 1551 - Frase Completa
// Alonso Martins
// 28/04/2024
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int contar_letras(char *f)
{
    int alf[26] = {};
    int i, s = 0;
    for (i = 0; i < strlen(f); i ++)
        if (isalpha(f[i]))
            s += (!alf[f[i] - 'a']++);
    return s;
}

int main()
{
    int N, qtd_letras, size;
    char frase[1002];

    scanf("%d%*c", &N);

    while (N --)
    {
        fgets(frase, sizeof(frase), stdin);
        size = strlen(frase);
        if (frase[size - 1] == '\n') frase[size - 1] = '\0';
        
        qtd_letras =  contar_letras(frase);
      
        printf("frase %s\n", qtd_letras == 26 ? "completa" : qtd_letras <= 14 ? "mal elaborada" : "quase completa");
    }

    return 0;
}
