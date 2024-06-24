// bee 1466 - Percurso em Arvore por Nível
// Alonso Martins
// 23/06/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    struct Node * left;
    struct Node * right;
} Node;

typedef struct BTree
{
    Node * root;
} BTree;


Node * create_node(int id)
{
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->id = id;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BTree * create_btree()
{
    BTree *bt = (BTree *)malloc(sizeof(BTree));
    bt->root = NULL;
    return bt;
}

void put_btree(BTree *btree, Node *node)
{
    if (btree->root == NULL)
    {
        btree->root = node;
        return;
    }

    Node *next, *parent = btree->root;
    if (node->id < parent->id) next = parent->left;
    else next = parent->right;

    while (next != NULL)
    {
        parent = next;
        if (node->id < parent->id) next = parent->left;
        else next = parent->right;
    }

    if (node->id < parent->id) parent->left = node;
    else parent->right = node;
}

void dump_bfs(BTree *btree)
{
    Node *queue[502], *next = btree->root;
    int inicio = 0, fim = -1, flag = 0;

    queue[++ fim] = next; 
    while (inicio <= fim)
    {
        next = queue[inicio ++];
        printf("%s%d", flag ++ ? " ": "", next->id);
        if (next->left) queue[++ fim] = next->left;
        if (next->right) queue[++ fim] = next->right;
    }
    printf("\n");
}

int main()
{
    int T, N, i, id, t;

    scanf("%d", &T);

    for (t = 1; t <= T; t ++)
    {
        scanf("%d", &N);
        BTree *btree = create_btree();

        for (i = 0; i < N; i ++)
        {
            scanf("%d", &id);
            Node *node = create_node(id);
            put_btree(btree, node);
        }

        printf("Case %d:\n", t);
        dump_bfs(btree);
        printf("\n");
    }

    return 0;
}
