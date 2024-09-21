// bee 1200 - Operacoes em ABP I
// Alonso Martins
// 20/09/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char c;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BTree
{
    Node *root;
} BTree;

Node *new_node(char);
void infixa(Node *, char *, int *);
void prefixa(Node *, char *, int *);
void posfixa(Node *, char *, int *);
void insert(char, BTree *);
int search(char, BTree *);

int main()
{
    char instrucao[11];
    BTree btree = { .root = NULL };

    while (scanf(" %10[^\n]", instrucao) != EOF)
    {
        char comando = instrucao[1];
        char saida[500] = {};
        int saida_len = 0;

        if (comando == 'N')
            infixa(btree.root, saida, &saida_len);
        else if (comando == 'R')
            prefixa(btree.root, saida, &saida_len);
        else if (comando == 'O')
            posfixa(btree.root, saida, &saida_len);
        else
        {
            comando = instrucao[0];
            char letra = instrucao[2];

            if (comando == 'I')
                insert(letra, &btree);
            else
                printf("%c%sexiste\n", letra, search(letra, &btree) ? " " : " nao ");
        }

        if (saida_len) printf("%s\n", saida); // se foi um comando de print, imprime a saida
    }

    return 0;
}

Node *new_node(char letra)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->c = letra;

    return node;
}

void insert(char letra, BTree *bt)
{
    if (bt->root == NULL)
    {
        bt->root = new_node(letra);
        return;
    }

    Node *node = bt->root;
    Node *next = node;
    int lado = 0;

    while (next)
    {
        node = next;
        if (letra > node->c)
        {
            lado = 2; // direita
            next = node->right;
        }
        else
        {
            lado = 1; // esquerda
            next = node->left;
        }
    }

    if (lado == 1)
        node->left = new_node(letra);
    else
        node->right = new_node(letra);
}

int search(char letra, BTree *bt)
{
    Node *node = bt->root;
    Node *next = node;

    while (next)
    {
        node = next;
        if (letra > node->c)
            next = node->right;
        else if (letra < node->c)
            next = node->left;
        else
            return 1;
    }

    return 0;
}

void infixa(Node *node, char *saida, int *saida_len)
{
    if (node == NULL)
        return;

    // infixa esquerda
    infixa(node->left, saida, saida_len);

    // adiciona o caractere
    if (*saida_len > 0) saida[(*saida_len) ++] = ' ';
    saida[(*saida_len) ++] = node->c;

    // infixa direita
    infixa(node->right, saida, saida_len);
}

void prefixa(Node *node, char *saida, int *saida_len)
{
    if (node == NULL)
        return;

    // adiciona o caractere
    if (*saida_len > 0) saida[(*saida_len) ++] = ' ';
    saida[(*saida_len) ++] = node->c;

    // prefixa esquerda
    prefixa(node->left, saida, saida_len);

    // prefixa direita
    prefixa(node->right, saida, saida_len);
}

void posfixa(Node *node, char *saida, int *saida_len)
{
    if (node == NULL)
        return;

    // posfixa esquerda
    posfixa(node->left, saida, saida_len);

    // posfixa direita
    posfixa(node->right, saida, saida_len);

    // adiciona o caractere
    if (*saida_len > 0) saida[(*saida_len) ++] = ' ';
    saida[(*saida_len) ++] = node->c;
}
