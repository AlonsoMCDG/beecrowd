// bee 1128 - Ir e Vir
// Alonso Martins
// 10/10/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 2001
#define UNVISITED -1

typedef long long ll;
typedef struct Node
{
    int id;
    int low;
    int neigh[MAX_N];
    int num_neigh;
} Node;

typedef struct Stack
{
    int nodes_ids[MAX_N];
    int size;
} Stack;

int min(int a, int b)
{
    return a < b ? a : b;
}

Node *nodes = NULL;
int sccCount = 0;
int id = 0;
Stack stack;
bool on_stack[MAX_N];

int pop()
{
    if (stack.size > 0)
        return stack.nodes_ids[-- stack.size];
    
    printf("pilha vazia\n");
    return 0;
}

void push(int id)
{
    stack.nodes_ids[stack.size ++] = id;
}

void dfs(int at)
{
    int i;
    push(at);
    on_stack[at] = true;
    nodes[at].id = nodes[at].low = id ++;

    for (i = 0; i < nodes[at].num_neigh; i ++)
    {
        int to = nodes[at].neigh[i];
        if (nodes[to].id == UNVISITED) dfs(to);
        if (on_stack[to]) nodes[at].low = min(nodes[at].low, nodes[to].low);
    }

    if (nodes[at].id == nodes[at].low)
    {
        int node;
        do
        {
            node = pop();
            on_stack[node] = false;
            nodes[node].low = nodes[at].id;
        } while (node != at);

        sccCount ++;
    }
}

int main()
{
    int N, M, i, v, w, p;
    nodes = (Node *)malloc(MAX_N * sizeof(Node));

    while (scanf("%d %d", &N, &M), N && M)
    {
        for (i = 0; i < N; i ++)
        {
            nodes[i].num_neigh = 0;
            nodes[i].id = UNVISITED;
            memset(nodes[i].neigh, 0, sizeof(nodes[i].neigh));
        }

        for (i = 0; i < M; i ++)
        {
            scanf("%d %d %d", &v, &w, &p);
            v --;
            w --;
            
            nodes[v].neigh[nodes[v].num_neigh ++] = w; // v para w

            if (p == 2) // eh de mao dupla
                nodes[w].neigh[nodes[w].num_neigh ++] = v; // w para v
        }

        sccCount = id = stack.size = 0;
        memset(on_stack, false, sizeof(on_stack));

        for (i = 0; i < N; i ++)
            if (nodes[i].id == UNVISITED)
                dfs(i);
        
        printf("%d\n", sccCount == 1);
    }

    return 0;
}
