// bee 2854 - Arvore Genealogica
// Alonso Martins
// 08/09/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DEBUG 0
#define debug if (DEBUG)

#define TABLE_SIZE 300
#define MAX_NODES 300

typedef struct Node
{
    char nome[30];
    int num_conexoes;
    int conexoes[MAX_NODES];
    int id;
} Node;

typedef struct HashTable
{
    Node nodes[TABLE_SIZE][10];
    int size[TABLE_SIZE];
} HashTable;

unsigned int hash(unsigned char *str)
{
    unsigned int hash = 5381, c;

    while ((c = *str ++))
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

int count_families(HashTable *, int);
int search(HashTable *, char *);
void add_conection(HashTable *, char *, char *);
int find(int *, int, HashTable *);

int search(HashTable *ht, char *nome_pessoa)
{
    unsigned int index = hash(nome_pessoa), i = 0;
    int p = index;

    // procura a pessoa na arvore
    for (i = 0; i < ht->size[index]; i ++)
        if (strcmp(ht->nodes[index][i].nome, nome_pessoa) == 0)
        { // a pessoa ja esta na arvore
            p += i * MAX_NODES;
            return p; // retorne a posicao dela
        }

    // a pessoa nao esta na arvore, entao adicione-a
    strcpy(ht->nodes[index][i].nome, nome_pessoa);
    ht->nodes[index][i].num_conexoes = 0;
    ht->size[index] ++;
    p += i * MAX_NODES;

    return p; // retorne a posicao dela
}

void add_conection(HashTable *ht, char *pessoa1, char *pessoa2)
{
    int pos_p1 = search(ht, pessoa1);
    int pos_p2 = search(ht, pessoa2);
    int index_p1 = pos_p1 % MAX_NODES, i_p1 = pos_p1 / MAX_NODES;
    int index_p2 = pos_p2 % MAX_NODES, i_p2 = pos_p2 / MAX_NODES;
    Node *p1 = &ht->nodes[index_p1][i_p1];
    Node *p2 = &ht->nodes[index_p2][i_p2];
    
    p1->conexoes[p1->num_conexoes ++] = pos_p2;
    p2->conexoes[p2->num_conexoes ++] = pos_p1;
}

int find(int *nodes, int p, HashTable *ht)
{
    int index = nodes[p] % MAX_NODES, i = nodes[p] / MAX_NODES;
    Node *root_node = &ht->nodes[index][i];
    int root = root_node->familia;

    // Find family root
    while (root != root_node->familia)
    {
        index = nodes[root] % 300;
        i = nodes[root] / 300;
        root_node = &ht->nodes[index][i];
        root = root_node->familia;
    }

    // Path compression
    int next = p;
    while (next != root)
    {
        index = nodes[next] % 300;
        i = nodes[next] / 300;
        ht->nodes[index][i].familia = root;
        next = ht->nodes[index][i].familia;
    }

    return root;
}

int count_families(HashTable *ht, int N)
{ // Algoritmo de Kruskal... (mais ou menos)
    int nodes[MAX_NODES]; // guarda os indices do node na hashtable
    int index, i, j, k = 0;
    int familias[MAX_NODES] = {}; // guarda em qual familia cada node esta
    int numero_familias = 0;

    // Inicializa o vetor de componentes.
    // Cada componente aponta para si mesmo com raiz da familia
    debug printf("Pessoas:\n");
    for (index = 0; index < TABLE_SIZE; index ++)
    {
        for (i = 0; i < ht->size[index]; i ++)
        {
            ht->nodes[index][i].id = k;
            nodes[k ++] = index + MAX_NODES * i;
        }
    }

    // conecta os nodes
    bool visitado[MAX_NODES] = {};
    for (k = 0; k < N; k ++)
    {
        debug printf("--------------------------\n");
        debug printf("searching families of %d (%s)\n", k, ht->nodes[nodes[k] % 300][nodes[k] / 300].nome);
        debug printf("familias: ");
        debug for (int z = 0; z < N; z ++) printf("%d ", familias[z]);
        debug printf("\n");

        int pilha[MAX_NODES] = { nodes[k] };
        int pilha_topo = 0;
        numero_familias += (familias[k] == 0);

        while (pilha_topo >= 0)
        {
            index = pilha[pilha_topo] % MAX_NODES;
            i = pilha[pilha_topo] / MAX_NODES;

            Node *pessoa = &ht->nodes[index][i];
            debug printf("pilha_topo = %d\n", pilha_topo);
            pilha_topo --;
            debug printf("pessoa = %d (%s): familia=%d\n", pessoa->id, pessoa->nome, familias[pessoa->id]);

            if (familias[pessoa->id] != 0)
                continue;

            familias[pessoa->id] = numero_familias;
            visitado[pessoa->id] = true;
            debug printf("new family=%d, visited=%d\n", familias[pessoa->id], visitado[pessoa->id]);
            debug printf("num_conexoes = %d\n", pessoa->num_conexoes);

            for (j = 0; j < pessoa->num_conexoes; j ++)
            {
                index = pessoa->conexoes[j] % MAX_NODES;
                i = pessoa->conexoes[j] / MAX_NODES;
                debug printf("j = %d: %d (%d,%d) | ", j, pessoa->conexoes[j], index, i);
                Node *next = &ht->nodes[index][i];
                debug printf("next = %d (%s): visited=%d\n", next->id, next->nome, visitado[next->id]);

                if (!visitado[next->id])
                    pilha[++ pilha_topo] = nodes[next->id];
            }
        }
    }

    return numero_familias;
}

int main()
{
    int N, M, i;
    char pessoa1[30], relacao[20], pessoa2[30];
    HashTable hashtable;
    memset(hashtable.size, 0, sizeof(hashtable.size));

    scanf("%d %d", &N, &M);

    for (i = 0; i < M; i ++)
    {
        scanf(" %s %s %s", pessoa1, relacao, pessoa2);
        add_conection(&hashtable, pessoa1, pessoa2);
    }

    printf("%d\n", count_families(&hashtable, N));

    return 0;
}
