// bee 2729 - Lista de Compras
// Alonso Martins
// 17/08/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1000
#define MAXN 1000

unsigned int hash(unsigned char *str)
{
    unsigned int hash = 0;
    char c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % TABLE_SIZE;
}


typedef struct Item
{
    char *nome;
} Item;

typedef struct HashTable
{
    Item itens[TABLE_SIZE][100];
    int size[TABLE_SIZE];
} HashTable;

void zerar(HashTable *ht)
{
    memset(ht->size, 0, sizeof(ht->size));
}

HashTable *new_hashtable()
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    zerar(ht);

    return ht;
}


// tenta inserir o item e retorna se conseguiu ou nao
bool insert(HashTable *ht, char *item)
{
    unsigned int index = hash(item), i;

    for (i = 0; i < ht->size[index]; i ++)
        if (strcmp(item, ht->itens[index][i].nome) == 0) // procura ele na lista
            return false; // encontrou, entao nao adicione
    
    // nao encontrou, entao adiciona o item a lista
    ht->itens[index][i].nome = strdup(item);
    ht->size[index] ++;
    return true;
}

int comp(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int main()
{
    int N, tamanhoLista, i;
    char listaDeCompras[20 * MAXN + 10];
    char *listaFinal[MAXN];
    scanf("%d", &N);
    HashTable hashtable;

    while (N -- && scanf(" %[^\n]", listaDeCompras))
    {
        zerar(&hashtable);
        tamanhoLista = 0;

        // separa a string listaDeCompras nos espacos
        char *item = strtok(listaDeCompras, " ");
        while (item != NULL)
        {
            if (insert(&hashtable, item))
            { // nao eh um item repetido
                listaFinal[tamanhoLista ++] = strdup(item);
            }

            item = strtok(NULL, " "); // pega o proximo item (ou NULL se for o fim da string)
        }

        // organiza a lista em ordem alfabetica
        qsort(listaFinal, tamanhoLista, sizeof(listaFinal[0]), comp);

        for (i = 0; i < tamanhoLista; i ++)
            printf("%s%s", listaFinal[i], i == tamanhoLista - 1 ? "\n" : " ");
    }

    return 0;
}
