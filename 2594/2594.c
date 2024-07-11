// bee 2594 - Eachianos II
// Alonso Martins
// 11/07/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 70

typedef struct Data
{
    char *string;
    int ocorrencias;
    int posicoes[70];
} Data;

typedef struct HashTable
{
    Data data[TABLE_SIZE][TABLE_SIZE];
    int size[TABLE_SIZE];
} HashTable;

unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str ++))
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

void add_position(HashTable *ht, char *s, int pos)
{
    unsigned long index = hash(s);
    int i;
    Data *data = NULL;

    for (i = 0; i < ht->size[index]; i ++)
    {
        data = &ht->data[index][i];
        if (strcmp(s, data->string) == 0)
        {
            data->posicoes[data->ocorrencias ++] = pos;
            return;
        }
    }

    data = &ht->data[index][ht->size[index] ++];
    data->posicoes[0] = pos;
    data->ocorrencias = 1;
    data->string = strdup(s);
}

void clear_table(HashTable *ht)
{
    memset(ht->size, 0, sizeof(ht->size));
}

void print_posicoes(HashTable *ht, char *s)
{
    unsigned long index = hash(s);
    int i;
    Data *data = NULL;

    for (i = 0; i < ht->size[index]; i ++)
    {
        data = &ht->data[index][i];
        if (strcmp(s, data->string) == 0)
        {
            for (i = 0; i < data->ocorrencias; i ++)
                printf("%d%s", data->posicoes[i], i < data->ocorrencias - 1 ? " " : "\n");
            return;
        }
    }

    printf("-1\n"); // nao encontrou
}

int main()
{
    int T, i, cont, pos;
    char c, palavra[130];
    HashTable *hashtable = (HashTable *)malloc(sizeof(HashTable));

    scanf("%d%*c", &T);

    while (T --)
    {
        clear_table(hashtable);
        i = cont = pos = 0;
        while (1)
        {
            c = getchar();
            if (c == ' ' || c == '\n')
            {
                palavra[i] = '\0';
                i = 0;
                add_position(hashtable, palavra, pos);

                pos = ++ cont;

                if (c == '\n')
                    break;
                continue;
            }

            palavra[i ++] = c;
            cont ++;
        }

        scanf(" %s%*c", palavra);
        print_posicoes(hashtable, palavra);
    }

    for (int i = 0; i < TABLE_SIZE; i++)
        for (int j = 0; j < hashtable->size[i]; j++)
            free(hashtable->data[i][j].string);
    free(hashtable);

    return 0;
}
