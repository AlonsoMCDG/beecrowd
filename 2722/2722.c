// bee 2722 - Pegadinha de Evergreen
// Alonso Martins
// 08/07/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, sz, _sz; scanf("%d", &N);
    char nome_completo[204], nome[102];

    while (N --)
    {
        scanf(" %100[^\n]", nome);
        sz = _sz = strlen(nome);

        for (i = 0; i < _sz; i += 2)
        {
            nome_completo[2 * i] = nome[i];
            nome_completo[2 * i + 1] = nome[i + 1];
        }

        scanf(" %100[^\n]", nome);
        sz += (_sz = strlen(nome));

        for (i = 0; i < _sz; i += 2)
        {
            nome_completo[2 + 2 * i] = nome[i];
            nome_completo[2 + 2 * i + 1] = nome[i + 1];
        }

        nome_completo[sz] = '\0';

        printf("%s\n", nome_completo);
    }
    

    return 0;
}
