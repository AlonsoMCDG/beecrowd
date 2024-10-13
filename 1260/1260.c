// bee 1260 - Especies de Madeira
// Alonso Martins
// 12/10/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000
#define TABLE_SIZE 10000

typedef struct Node
{
    char nome[32];
    int quantidade;
    struct Node *next; // linked list
} Node;

typedef struct HashTable
{
    Node *nodes[TABLE_SIZE];
} HashTable;

Node list_especies[MAX_N];
int num_especies = 0;

void clear(HashTable *ht) {
    // limpa cada lista ligada da tabela hash
    for (int i = 0; i < TABLE_SIZE; i ++)
    {
        ht->nodes[i] = NULL;
    }

    // limpa o array de list_especies
    for (int i = 0; i < MAX_N; i ++)
    {
        list_especies[i].next = NULL;
        list_especies[i].quantidade = 0;
        memset(list_especies[i].nome, 0, sizeof(list_especies[i].nome));
    }

    // reseta num_especies
    num_especies = 0;
}

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

Node *search(char *nome_especie, HashTable *ht)
{
    unsigned int index = hash(nome_especie);
    Node *node = ht->nodes[index];

    while (node)
    {
        if (strcmp(node->nome, nome_especie) == 0)
            break;

        node = node->next;
    }

    return node;
}

void insert(Node *especie, HashTable *ht)
{
    unsigned int index = hash(especie->nome);

    // insere no inicio da lista linkada
    especie->next = ht->nodes[index];
    ht->nodes[index] = especie;
}

Node *new_node(char *nome)
{
    strcpy(list_especies[num_especies].nome, nome);
    return &list_especies[num_especies ++];
}

int comp(const void *a, const void *b)
{
    return strcmp(((Node *)a)->nome, ((Node *)b)->nome);
}

int main()
{
    int N, i, total = 0;
    char nome_especie[32];
    HashTable hashtable;

    scanf("%d\n", &N);

    while (N --)
    {
        clear(&hashtable);
        total = 0;

        while (fgets(nome_especie, sizeof(nome_especie), stdin))
        {
            if (strcmp(nome_especie, "\n") == 0)
                break;

            nome_especie[strcspn(nome_especie, "\n")] = '\0';

            Node *arvore = search(nome_especie, &hashtable);

            if (arvore == NULL)
                insert(arvore = new_node(nome_especie), &hashtable);

            arvore->quantidade ++;
            total ++;
        }

        // ordena lexicograficamente (ordem alfabetica) para a saida
        qsort(list_especies, num_especies, sizeof(list_especies[0]), comp);

        for (i = 0; i < num_especies; i ++)
        {
            printf("%s %.4lf\n", list_especies[i].nome, list_especies[i].quantidade * 100.0 / total);
        }

        if (N) printf("\n"); // pula linha se ha mais casos
    }

    return 0;
}
