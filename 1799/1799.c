// bee 1799 - O Rato no Labirinto
// Alonso Martins
// 09/09/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define DEBUG 0
#define debug if (DEBUG)

#define MAX_VIZINHOS 50
#define TABLE_SIZE 10001
#define MAX_NODES 4000
#define NAME_SIZE 30

typedef struct Node
{
    char nome[NAME_SIZE];
    struct Node **vizinhos; // vizinhos conectados
    struct Node *next; // proximo na lista linkada da HashTable
    int num_vizinhos;
    int max_vizinhos;
    int pos; // index na lista de distancias
} Node;

Node mem[MAX_NODES];
int mem_nodes = 0;

typedef struct HashTable
{
    Node *nodes[TABLE_SIZE];
} HashTable;

unsigned int hash(unsigned char *str)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *str ++))
        hash = ((hash >> 5) + hash) + hash;

    return hash % TABLE_SIZE;
}

Node *new_node(char *nome)
{
    Node *n = &mem[mem_nodes];
    strcpy(n->nome, nome);
    n->num_vizinhos = 0;
    n->max_vizinhos = 4;
    n->vizinhos = malloc(n->max_vizinhos * sizeof(Node *));
    n->pos = mem_nodes ++;

    return n;
}

Node *search(char *nome, HashTable *graph)
{
    unsigned int index = hash(nome);

    if (graph->nodes[index] == NULL)
    {
        graph->nodes[index] = new_node(nome);
        return graph->nodes[index];
    }
    else
    {
        Node *atual = graph->nodes[index];
        while (true)
        {
            if (strcmp(atual->nome, nome) == 0)
                return atual;

            if (atual->next == NULL)
                break;

            atual = atual->next;
        }

        atual->next = new_node(nome);
        return atual->next;
    }
}
void add_vizinho(Node *node, Node *vizinho)
{
    if (node->num_vizinhos == node->max_vizinhos)
    {
        node->max_vizinhos <<= 1;
        node->vizinhos = realloc(node->vizinhos, node->max_vizinhos * sizeof(Node *));
    }
    node->vizinhos[node->num_vizinhos ++] = vizinho;
}

void add_path(char *A, char *B, HashTable *graph)
{
    Node *n1 = search(A, graph);
    Node *n2 = search(B, graph);
    add_vizinho(n1, n2);
    add_vizinho(n2, n1);
}

int bfs(Node *start, Node *target, int *queue, bool *visited, int *distancia)
{
    int i, queue_front = 0, queue_end = 0;

    queue[queue_end ++] = start->pos;
    visited[start->pos] = true;

    Node *curr;
    while (queue_front < queue_end)
    {
        curr = &mem[queue[queue_front ++]];
        debug printf("curr = %s\n", curr->nome);

        if (curr == target)
        {
            debug printf("distancia de %s ate %s = %d\n", start->nome, target->nome, distancia[target->pos]);
            return distancia[target->pos];
        }

        debug printf("vizinhos de %s = ", curr->nome);
        for (i = 0; i < curr->num_vizinhos; i ++)
        {
            debug printf("[%s]", curr->vizinhos[i]->nome);
            if (!visited[curr->vizinhos[i]->pos])
            {
                queue[queue_end ++] = curr->vizinhos[i]->pos;
                visited[curr->vizinhos[i]->pos] = true;
                distancia[curr->vizinhos[i]->pos] = distancia[curr->pos] + 1;
            }
        }
        debug printf("\n");
    }

    return 0;
}

int main()
{
    int N, M, i;
    char A[40], B[40];
    HashTable graph;
    memset(graph.nodes, 0, sizeof(graph.nodes));

    scanf("%d %d", &N, &M);

    for (i = 0; i < M; i ++)
    {
        scanf(" %s %s", A, B);
        debug printf("[%s,%s]\n", A, B);
        add_path(A, B, &graph);
    }

    
    int queue[MAX_NODES];
    bool visited[MAX_NODES] = {};
    int distancia[MAX_NODES] = {};

    Node *entrada = search("Entrada", &graph);
    Node *queijo = search("*", &graph);
    Node *saida = search("Saida", &graph);

    int dist1 = bfs(entrada, queijo, queue, visited, distancia);
    
    memset(visited, 0, sizeof(visited));
    memset(distancia, 0, sizeof(distancia));

    int dist2 = bfs(queijo, saida, queue, visited, distancia);

    printf("%d\n", dist1 + dist2);    

    return 0;
}
