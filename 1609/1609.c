// bee 1609 - Contando Carneirinhos
// Alonso Martins
// 28/08/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 100

typedef struct HashTable
{
    int itens[TABLE_SIZE][TABLE_SIZE];
    int size[TABLE_SIZE];

} HashTable;

void clear(HashTable *hashtable)
{
    memset(hashtable->size, 0, sizeof(hashtable->size));
}

bool insert(HashTable *hashtable, int item)
{
    int i, index = item % TABLE_SIZE;

    for (i = 0; i < hashtable->size[index]; i ++)
        if (hashtable->itens[index][i] == item)
            return false;

    hashtable->itens[index][hashtable->size[index] ++] = item;
    return true;
}

int main()
{
    int T, N, i, ans, carneiro;
    HashTable *carneiros = (HashTable *)malloc(sizeof(HashTable));

    scanf("%d", &T);

    while (T -- && scanf("%d", &N))
    {
        clear(carneiros);
        ans = 0;

        for (i = 0; i < N; i ++)
        {
            scanf("%d", &carneiro);
            ans += insert(carneiros, carneiro);
        }

        printf("%d\n", ans);
    }

    return 0;
}
