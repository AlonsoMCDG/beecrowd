// bee 2583 - Chirrin Chirrion
// Alonso Martins
// 19/08/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1000

typedef struct Item
{
    char *nome;
    bool TausfoPossui;
} Item;

typedef struct HashTable
{
    Item itens[TABLE_SIZE][TABLE_SIZE / 10];
    int size[TABLE_SIZE];
} HashTable;

unsigned int hash(char *str)
{
    unsigned int hash = 0;
    int c;

    while ((c = *str ++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % TABLE_SIZE;
}

void clear(HashTable *ht)
{
    memset(ht->size, 0, sizeof(ht->size));
}

void insert(HashTable *ht, char *coisa)
{
    unsigned int index = hash(coisa), i;

    for (i = 0; i < ht->size[index]; i ++)
        if (strcmp(coisa, ht->itens[index][i].nome) == 0)
        { // Tausfo ja possui essa coisa
            ht->itens[index][i].TausfoPossui = true;
            return;
        }
    
    // Tausfo nao possui essa coisa
    ht->itens[index][i].nome = strdup(coisa);
    ht->itens[index][i].TausfoPossui = true;
    ht->size[index] ++;
}

void delete(HashTable *ht, char *coisa)
{
    unsigned int index = hash(coisa), i;

    for (i = 0; i < ht->size[index]; i ++)
    {
        if (ht->itens[index][i].TausfoPossui && strcmp(coisa, ht->itens[index][i].nome) == 0)
        { // ele possui essa coisa, entao marca que ele nao possui
            ht->itens[index][i].TausfoPossui = false;
        }
    }
}

int comp(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int main()
{
    int N, T, i, j;
    char coisa[50], comando[50];
    HashTable *hashtable = (HashTable *)malloc(sizeof(HashTable));

    scanf("%d", &T);

    while (T -- && scanf("%d", &N))
    {
        clear(hashtable);
        
        for (i = 0; i < N; i ++)
        {
            scanf(" %s %s", coisa, comando);

            if (!strcmp(comando, "chirrin"))
                insert(hashtable, coisa);
            else if (!strcmp(comando, "chirrion"))
                delete(hashtable, coisa);
        }

        char *posses[N];
        int qtdPosses = 0;

        for (i = 0; i < TABLE_SIZE; i ++)
        {
            for (j = 0; j < hashtable->size[i]; j ++)
            {

                if (hashtable->itens[i][j].TausfoPossui)
                {
                    posses[qtdPosses ++] = hashtable->itens[i][j].nome;
                }
            }
        }

        qsort(posses, qtdPosses, sizeof(posses[0]), comp);

        printf("TOTAL\n");
        for (i = 0; i < qtdPosses; i ++)
        {
            printf("%s\n", posses[i]);
        }
    }


    return 0;
}
