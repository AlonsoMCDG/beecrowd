// bee 2492 - Ilhas Isoladas
// Alonso Martins
// 06/08/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 100

typedef struct Ilha
{
    char *nome;
    struct Ilha * conexao;
    struct Ilha * integral;
    struct Ilha * next;  // next in linked list
} Ilha;

typedef struct HashMap
{
    Ilha * ilhas[TABLE_SIZE];
} HashMap;

// função hash
unsigned hash(unsigned char *str)
{
    unsigned hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

HashMap * new_hashmap()
{
    int i;
    HashMap *hm = (HashMap *)malloc(sizeof(HashMap));

    for (i = 0; i < TABLE_SIZE; i ++)
        hm->ilhas[i] = NULL;

    return hm;
}

Ilha * new_island(char *name)
{
    Ilha *new_i = (Ilha *)malloc(sizeof(Ilha));

    new_i->nome = strdup(name);
    new_i->integral = NULL;
    new_i->conexao = NULL;
    new_i->next = NULL;

    return new_i;
}

void * insert(HashMap * hashmap, Ilha * ilha)
{
    unsigned index = hash(ilha->nome);

    if (hashmap->ilhas[index] == NULL)
    {
        hashmap->ilhas[index] = ilha;
    }
    else
    {
        Ilha *aux = hashmap->ilhas[index];
        
        while (aux->next)
            aux = aux->next;
        
        aux->next = ilha;
    }
}

Ilha * search(HashMap * hashmap, char *island_name)
{
    unsigned index = hash(island_name);
    Ilha *ilha = hashmap->ilhas[index];

    while (ilha && strcmp(ilha->nome, island_name) != 0)
        ilha = ilha->next;

    return ilha;
}

int main()
{
    int T, i;
    char x[32], y[32];
    
    while (scanf("%d", &T), T)
    {
        bool is_function = true;
        bool is_invertible = true;
        HashMap *hashmap = new_hashmap();

        for (i = 0; i < T; i ++)
        {
            scanf(" %s %*c%*c %s", x, y);

            Ilha *ilha_x = search(hashmap, x);
            Ilha *ilha_y = search(hashmap, y);

            if (!ilha_x) insert(hashmap, (ilha_x = new_island(x)));
            if (!ilha_y) insert(hashmap, (ilha_y = new_island(y)));

            if (ilha_x->conexao && ilha_x->conexao != ilha_y) is_function = false;
            if (ilha_y->integral && ilha_y->integral != ilha_x) is_invertible = false;

            ilha_x->conexao = ilha_y;
            ilha_y->integral = ilha_x;
        }

        if (!is_function) printf("Not a function.\n");
        else if (is_invertible) printf("Invertible.\n");
        else printf("Not invertible.\n");

        free(hashmap);
    }

    return 0;
}
