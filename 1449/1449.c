// bee 1449 - O Fantastico Jaspion
// Alonso Martins
// 18/06/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 103
#define ENTRYSIZE 1000

typedef struct Data
{
    char *key;
    char *value;
} Data;

typedef struct Entry
{
    int size;
    Data *data;
} Entry;

typedef struct HashMap
{
    Entry *entries;
} HashMap;

HashMap *create_hashmap();
unsigned long hash_djb2(const char *str);
void put(HashMap *hashmap, char *key, char *value);
char *get(HashMap *hashmap, char *key);
void free_hashmap(HashMap *hashmap);

int main()
{
    int T, M, N, i;
    char key[82], frase[82], *p, *traducao;
    
    scanf("%d", &T);

    while (T -- && scanf("%d %d", &M, &N))
    {
        HashMap *hashmap = create_hashmap();
        for (i = 0; i < M; i ++)
        {
            scanf(" %s%*c%82[^\n]%*c", key, frase);
            put(hashmap, key, frase);
        }

        for (i = 0; i < N; i ++)
        {
            scanf(" %82[^\n]", frase);
            
            p = strtok(frase, " ");
            while (p != NULL)
            {
                traducao = get(hashmap, p);
                printf("%s", traducao ? traducao : p);
                p = strtok(NULL, " ");
                printf("%s", p == NULL ? "\n" : " ");
            }
        }
        printf("\n");
        // free_hashmap(hashmap);
    }


    return 0;
}

unsigned long hash_djb2(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}

HashMap *create_hashmap()
{
    int i;
    HashMap *hashmap = (HashMap *)malloc(sizeof(HashMap));
    hashmap->entries = (Entry *)calloc(TABLE_SIZE, sizeof(Entry));

    for (i = 0; i < TABLE_SIZE; i ++)
    {
        hashmap->entries[i].data = (Data *)malloc(ENTRYSIZE * sizeof(Data));
        hashmap->entries[i].size = 0;
    }

    return hashmap;
}

void put(HashMap *hashmap, char *key, char *value)
{
    int index = hash_djb2(key);
    Entry *entry = &hashmap->entries[index];

    if (entry->size < ENTRYSIZE) {
        entry->data[entry->size].key = strdup(key);
        entry->data[entry->size].value = strdup(value);
        entry->size ++;
    } else {
        // Tratamento para caso não haja mais espaço na entrada
        printf("Moiou :(\n");
    }
}

char *get(HashMap *hashmap, char *key)
{
    int index = hash_djb2(key), achou;
    Entry *entry = &hashmap->entries[index];

    if (index = 0, entry->size == 1)
        return entry->data[0].value;

    for (index = 0; index < entry->size; index ++)
        if (strcmp(entry->data[index].key, key) == 0)
            return entry->data[index].value;

    return NULL;
}

void free_hashmap(HashMap *hashmap) {
    int i, j;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        for (j = 0; j < hashmap->entries[i].size; j++)
        {
            free(hashmap->entries[i].data[j].key);
            free(hashmap->entries[i].data[j].value);
        }
        free(hashmap->entries[i].data);
    }

    free(hashmap->entries);
    free(hashmap);
}
