// bee 2018 - Olimpiadas de Natal
// Alonso Martins
// 25/09/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 500
#define NAME_SIZE 50
#define OURO 0
#define PRATA 1
#define BRONZE 2

typedef struct Pais
{
    char nome[NAME_SIZE];
    int ouros;
    int pratas;
    int bronzes;
    int indice;
} Pais;

typedef struct HashTable
{
    Pais *paises[TABLE_SIZE][50];
    int size[TABLE_SIZE];
} HashTable;

Pais paises[300] = {};
int num_paises = 0;

unsigned int hash(unsigned char *str)
{
    unsigned int hash = 5381, c;

    while ((c = *str ++))
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

int getIndex(char *nome_pais, HashTable *ht)
{
    unsigned int index = hash(nome_pais), i = 0;

    for (i = 0; i < ht->size[index]; i ++)
        if (strcmp(nome_pais, ht->paises[index][i]->nome) == 0)
            return ht->paises[index][i]->indice;

    Pais *pais = &paises[num_paises];

    strcpy(pais->nome, nome_pais);
    pais->indice = num_paises ++;
    ht->paises[index][i] = pais;
    ht->size[index] ++;

    return pais->indice;
}

void give_medal(char *nome_pais, int medalha, HashTable *ht)
{
    unsigned int index = getIndex(nome_pais, ht);
    Pais *pais = &paises[index];

    if (medalha == OURO)
        pais->ouros ++;
    else if (medalha == PRATA)
        pais->pratas ++;
    else
        pais->bronzes ++;
}

int comp(const void *_a, const void *_b)
{
    Pais *A = (Pais *)_a, *B = (Pais *)_b;

    int o = (B->ouros - A->ouros);
    int p = (B->pratas - A->pratas);
    int b = (B->bronzes - A->bronzes);
    int nome = strcmp(A->nome, B->nome);

    return o ? o : p ? p : b ? b : nome;
}

int main()
{
    HashTable quadro; // quadro de medalhas
    memset(quadro.size, 0, sizeof(quadro.size));
    char modalidade[200], pais_ouro[NAME_SIZE], pais_prata[NAME_SIZE], pais_bronze[NAME_SIZE];
    int index, i;

    while (scanf(" %[^\n]", modalidade) != EOF)
    {
        scanf(" %[^\n] %[^\n] %[^\n]", pais_ouro, pais_prata, pais_bronze);

        give_medal(pais_ouro, OURO, &quadro);
        give_medal(pais_prata, PRATA, &quadro);
        give_medal(pais_bronze, BRONZE, &quadro);
    }

    qsort(paises, num_paises, sizeof(paises[0]), comp);

    printf("Quadro de Medalhas\n");
    for (i = 0; i < num_paises; i ++)
    {
        Pais *p = &paises[i];
        printf("%s %d %d %d\n", p->nome, p->ouros, p->pratas, p->bronzes);
    }

    return 0;
}
