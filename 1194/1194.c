// bee 1194 - Prefixa, Infixa e Posfixa
// Alonso Martins
// 14/7/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 20
#define MAX_N 52
#define DEBUG 0
#define debug if (DEBUG)

typedef struct Node
{
    char *id;
    struct Node *parent;
    struct Node *left_child;
    struct Node *right_child;
} Node;

typedef struct Stack
{
    int top;
    Node *nodes[53];
} Stack;

void insert(Stack *stack, Node *node)
{
    stack->nodes[++ stack->top] = node;
}

Node *top(Stack *stack)
{
    return stack->top != -1 ? stack->nodes[stack->top] : NULL;
}

Node *pop(Stack *stack)
{
    return stack->top != -1 ? stack->nodes[stack->top --] : NULL;
}

Node nodes_pool[53];
int free_address = 0;

void free_pool()
{
    free_address = 0;
}

Node *new_node(char *id, Node *parent)
{
    Node *new_node = &nodes_pool[free_address ++];
    new_node->id = strdup(id);
    new_node->parent = parent;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void split_ids(char *s1, char *s2, char ids_s1[MAX_N][MAX_LEN], char ids_s2[MAX_N][MAX_LEN], int N)
{
    int i, j;
    int len = strlen(s1);
    int sz = len / N;

    for (i = 0; i < N; i ++)
    {
        for (j = 0; j < sz; j ++)
        {
            ids_s1[i][j] = s1[i * sz + j];
            ids_s2[i][j] = s2[i * sz + j];
        }

        ids_s1[i][j] = '\0';
        ids_s2[i][j] = '\0';
    }
}

void build_graph(Node *root, char ids_s1[MAX_N][MAX_LEN], char ids_s2[MAX_N][MAX_LEN], int N)
{
    Node *parent = new_node(ids_s1[0], NULL);
    root->left_child = parent;
    Node *node;

    Stack stack = { .top = -1 };
    insert(&stack, parent);

    int i = 0, j = 0;
    while (i < N && j < N)
    {
        while (i < N && strcmp(ids_s1[i], ids_s2[j]))
        {
            i ++;
            node = new_node(ids_s1[i], parent);
            insert(&stack, node);

            if (parent->left_child == NULL)
                parent->left_child = node;
            else
                parent->right_child = node;

            parent = node;
        }

        while (j < N && parent != NULL && strcmp(parent->id, ids_s2[j]) == 0)
        {
            j ++;
            node = parent;
            pop(&stack);
            parent = top(&stack);
        }
        parent = node;
    }
}

void print_graph(Node *root)
{
    if (root == NULL) return;
    printf("%s: %s %s\n", root->id, root->left_child ? root->left_child->id : "[]", root->right_child ? root->right_child->id : "[]");
    if (root->left_child) print_graph(root->left_child);
    if (root->right_child) print_graph(root->right_child);
}

char postfix_string[MAX_N * MAX_LEN];
int len_post = 0;

void get_postfix_string(Node *node, int sz)
{
    if (node == NULL)
        return;
    
    get_postfix_string(node->left_child, sz);
    get_postfix_string(node->right_child, sz);

    int i;
    for (i = 0; i < sz; i ++)
        postfix_string[len_post ++] = node->id[i];
    postfix_string[len_post] = '\0';
}

int main()
{
    int C, N, i, j, k, sz;
    char s1[MAX_N * MAX_LEN];
    char s2[MAX_N * MAX_LEN];

    char ids_s1[MAX_N][MAX_LEN];
    char ids_s2[MAX_N][MAX_LEN];

    scanf("%d", &C);

    while (C -- && scanf("%d %s %s", &N, s1, s2))
    {
        split_ids(s1, s2, ids_s1, ids_s2, N);
        free_pool();
        Node *root = new_node("root", NULL);
        build_graph(root, ids_s1, ids_s2, N);

        len_post = 0;
        sz = strlen(ids_s1[0]);
        get_postfix_string(root->left_child, sz);

        printf("%s\n", postfix_string);
    }

    return 0;
}
