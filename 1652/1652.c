// bee 1652 - Deli Deli
// Alonso Martins
// 25/05/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char palavra[22], plural[22];
} plural;

int ehVogal(char c)
{
    return strspn(&c, "aeiou");
}

char * buscar(char *p, plural *lista, int N)
{
    int i;
    for (i = 0; i < N; i ++)
        if (!strcmp(lista[i].palavra, p))
            return lista[i].plural;
    return NULL;
}

int main()
{
    int L, N, i, sz;
    scanf("%d %d", &L, &N);
    plural irregular[L];

    for (i = 0; i < L; i ++)
        scanf(" %s %s", irregular[i].palavra, irregular[i].plural);

    char p[22], *plural;
    for (i = 0; i < N && scanf(" %s", p); i ++)
    {
        if (plural = buscar(p, irregular, L), plural != NULL)
        {
            printf("%s\n", plural);
            continue;
        } 
        if (sz = strlen(p), sz > 1)
            if (!ehVogal(p[sz - 2]) && p[sz - 1] == 'y')
            {
                p[sz - 1] = '\0';
                printf("%sies\n", p);
                continue;
            } else if (!strcmp(&p[sz - 2], "ch") || !strcmp(&p[sz - 2], "sh"))
            {
                printf("%ses\n", p);
                continue;
            }
        if (strspn(&p[sz - 1], "osx"))
            printf("%ses\n", p);
        else
            printf("%ss\n", p);
    }

    return 0;
}
