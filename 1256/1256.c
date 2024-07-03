// bee 1256 - Tabelas Hash
// Alonso Martins
// 03/07/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable
{
    int elements[100][200];
    int elements_size[100];
    int size;
} HashTable;

void setup_hashtable(HashTable *ht)
{
    ht->size = 100;
    memset(ht->elements, 0, sizeof(ht->elements));
    memset(ht->elements_size, 0, sizeof(ht->elements_size));
}

void clear(HashTable *hashtable, int new_size)
{
    memset(hashtable->elements_size, 0, sizeof(hashtable->elements_size));
    hashtable->size = new_size;
}

void insert(HashTable *hashtable, int key)
{
    int index = key % hashtable->size;
    hashtable->elements[index][hashtable->elements_size[index] ++] = key;
}

void list_childs(HashTable *ht, int index)
{
    int i;
    printf("%d ->", index);
    for (i = 0; i < ht->elements_size[index]; i ++)
        printf(" %d ->", ht->elements[index][i]);
    printf(" \\\n");
}

int main()
{
    int N, M, C, i, key;
    HashTable hashtable;
    setup_hashtable(&hashtable);

    scanf("%d", &N);
    
    while (N -- && scanf("%d %d", &M, &C))
    {
        clear(&hashtable, M);

        for (i = 0; i < C; i ++)
            scanf("%d", &key), insert(&hashtable, key);

        for (i = 0; i < M; i ++)
            list_childs(&hashtable, i);

        if (N) printf("\n");
    }

    return 0;
}
