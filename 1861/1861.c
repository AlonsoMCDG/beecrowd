// bee 1861 - O Hall dos Assassinos
// Alonso Martins
// 04/01/2025
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 200000
#define TABLE_SIZE 200000

typedef struct Murderer
{
    char name[12];
    int kills;
    bool alive;
    struct Murderer *next;
} Murderer;

typedef struct HashTable
{
    Murderer *item[TABLE_SIZE];
} HashTable;

// alocação estática de memória para evitar alocação dinâmica
Murderer murderers_list[MAX_N];
int count_murderers_list;

int comp(const void *a, const void *b)
{
    Murderer *A = (Murderer *)a, *B = (Murderer *)b;

    return strcmp(A->name, B->name);
}

HashTable *new_hashtable()
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    memset(ht->item, 0, sizeof(ht->item));

    return ht;
}

unsigned int hash(unsigned char *str)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *str ++))
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

Murderer *new_murderer(char *name)
{
    Murderer *murderer = &murderers_list[count_murderers_list ++];

    strcpy(murderer->name, name);
    murderer->kills = 0;
    murderer->alive = true;
    murderer->next = NULL;

    return murderer;
}

void insert(Murderer *murderer, HashTable *ht)
{
    unsigned int index = hash(murderer->name);

    murderer->next = ht->item[index];
    ht->item[index] = murderer;
}

Murderer *get_murderer(char *name, HashTable *ht)
{
    unsigned int index = hash(name);

    Murderer *murderer = ht->item[index];

    while (murderer && strcmp(murderer->name, name) != 0)
        murderer = murderer->next;

    return murderer;
}

int main()
{
    HashTable *hash_table = new_hashtable();
    char murderer[12], victim[12];
    int i;

    while (scanf(" %s %s", murderer, victim) != EOF)
    {
        Murderer *m = get_murderer(murderer, hash_table);
        if (!m) insert(m = new_murderer(murderer), hash_table);
        m->kills ++;

        Murderer *v = get_murderer(victim, hash_table);
        if (!v) insert(v = new_murderer(victim), hash_table);
        v->alive = false;
    }

    qsort(murderers_list, count_murderers_list, sizeof(murderers_list[0]), comp);

    printf("HALL OF MURDERERS\n");
    for (i = 0; i < count_murderers_list; i ++)
    {
        if (murderers_list[i].alive)
            printf("%s %d\n", murderers_list[i].name, murderers_list[i].kills);
    }

    return 0;
}
