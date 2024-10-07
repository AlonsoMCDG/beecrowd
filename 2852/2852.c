// bee 2852 - Troca de Mensagens
// Alonso Martins
// 07/10/2024
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ord(x) ((x) - 'a')
#define chr(x) ((x) + 'a')

bool eh_vogal(char c)
{
    return strchr("aeiou", c) != NULL;
}

int main()
{
    int N, i, j, k, linha, coluna, len_chave, acc, sz;
    char chave[50], msg[100002], ant;

    scanf("%s %d", chave, &N);
    len_chave = strlen(chave);

    for (i = 0; i < N; i ++)
    {
        scanf(" %[^\n]", msg);
        acc = 0;
        ant = ' ';
        sz = strlen(msg);

        for (j = 0; msg[j]; j ++)
        {
            if (ant == ' ' && !eh_vogal(msg[j]))
            {
                for (; msg[j] && msg[j] != ' '; j ++)
                {
                    linha = ord(chave[acc % len_chave]);
                    coluna = ord(msg[j]);

                    msg[j] = chr((linha + coluna) % 26);
                    acc ++;
                }
            }
            ant = msg[j];
        }

        printf("%s\n", msg);
    }

    return 0;
}
