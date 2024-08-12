// bee 1911 - Ajude Girafales
// Alonso Martins
// 12/08/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 50

typedef struct Aluno
{
    char *nome;
    char *assinatura;
} Aluno;

typedef struct HashMap
{
    Aluno alunos[TABLE_SIZE][TABLE_SIZE];
    unsigned int size[TABLE_SIZE];
} HashMap;

unsigned int hash(unsigned char *str)
{
    unsigned int hash = 0;
    int c;

    while ((c = *str ++))
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

void clear(HashMap *hashmap)
{
    int i;
    for (i = 0; i < TABLE_SIZE; i ++)
        hashmap->size[i] = 0;
}

void insert(HashMap *hashmap, char *nome, char *assinatura)
{
    unsigned int index = hash(nome);
    hashmap->alunos[index][hashmap->size[index]].nome = strdup(nome);
    hashmap->alunos[index][hashmap->size[index]].assinatura = strdup(assinatura);
    hashmap->size[index] ++;
}

Aluno * get(HashMap *hashmap, char *nome)
{
    unsigned int index = hash(nome), i;

    for (i = 0; i < hashmap->size[index]; i ++)
    {
        if (strcmp(hashmap->alunos[index][i].nome, nome) == 0)
            return &hashmap->alunos[index][i];
    }

    return NULL;
}

int diferencas(char *s1, char *s2)
{
    int cont = 0, i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if (s1[i] != s2[i]) cont++;
        if (cont >= 2) break;
    }

    return cont;
}

int main()
{
    int N, M, i, assinaturas_falsas;
    HashMap *hashmap = (HashMap *)malloc(sizeof(HashMap));

    while (scanf("%d%*c", &N), N)
    {
        char nome[22], assinatura[22];
        clear(hashmap);

        for (i = 0; i < N; i ++)
        {
            scanf(" %s %s", nome, assinatura);
            insert(hashmap, nome, assinatura);
        }

        scanf("%d%*c", &M);

        assinaturas_falsas = 0;
        for (i = 0; i < M; i ++)
        {
            scanf(" %s %s", nome, assinatura);

            Aluno *aluno = get(hashmap, nome);
            assinaturas_falsas += (diferencas(aluno->assinatura, assinatura) > 1);
        }

        printf("%d\n", assinaturas_falsas);
    }

    free(hashmap);

    return 0;
}
