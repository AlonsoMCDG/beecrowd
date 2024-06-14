// bee 2430 - Catalogo de Musicas
// Alonso Martins
// 12/06/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN_CAMINHO 2102000
#define TABLE_SIZE 20

#define DEBUG 0
#define debug if(DEBUG)

typedef struct Node
{
    char *file;
    int fileLength;
    int numLeafs;  // arquivos (folhas) nessa pasta
    int numChilds;  // filhos diretos de Node
    int pathLength;  // comprimento do caminho completo de todos os arquivos desta pasta
    int childsPathLength;  // soma dos 'pathLength' dos filhos
    int othersPathLength;  // pathlegth da pasta 'root' sem contar esta pasta
    int pathLengthAsRoot;  // tamanho do catalogo se Node eh a nova pasta raiz
    struct HashTable *childs;
    struct Node *next;
    struct Node *parent;
} Node;

typedef struct HashTable
{
    struct Node **table;
} HashTable;

typedef struct File
{
    Node *root;
} File;

unsigned int hash_function(const char *key)
{ // operacoes quaisquer para a funcao hash
    int i, sz = strlen(key);
    unsigned int hash = 0;
    for (i = 0; i < sz; i ++)
    {
        hash += (key[i] * (i + 1));
    }
    return hash % TABLE_SIZE;
}

HashTable *create_hash_table()
{
    HashTable *new_table = (HashTable *)malloc(sizeof(HashTable));
    new_table->table = (Node **)calloc(TABLE_SIZE, sizeof(Node *));
    return new_table;
}

Node *create_node(const char *file, Node *parent)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->file = strdup(file);
    new_node->fileLength = strlen(file);
    new_node->pathLength = new_node->fileLength;
    new_node->numLeafs = 0;
    new_node->childsPathLength = 0;
    new_node->othersPathLength = 0;
    new_node->pathLengthAsRoot = 0;
    new_node->next = NULL;
    new_node->parent = parent;
    new_node->childs = create_hash_table();
    return new_node;
}

File *create_file()
{
    File *file = (File *)malloc(sizeof(File));
    file->root = create_node("", NULL);
    return file;
}

void updateNumChilds(Node *node)
{
    node->numLeafs ++;
    debug printf("new child to %s!! %d in total.\n", node->file, node->numLeafs); /*debug*/

    if (node->parent != NULL)   
        updateNumChilds(node->parent);
}

Node *find_child(Node *node, const char *file)
{
    while (node != NULL)
    {
        if (strcmp(node->file, file) == 0)
            return node;
        node = node->next;
    }
    return NULL;
}

Node *add_child(Node *parent, const char *file)
{
    unsigned int index = hash_function(file);
    Node *child = create_node(file, parent);
    Node *node = find_child(parent->childs->table[index], file);

    debug printf("adding node %10s/%-10s - hash (%d)", parent->file, file, index); /*debug*/

    if (node)
    {
        debug printf(" - ja existe\n"); /*debug*/
        return node; // essa pasta/node ja existe
    }
    debug printf(" - eh nova\n"); /*debug*/

    child->next = parent->childs->table[index];
    parent->childs->table[index] = child; // insere no inicio da lista encadeada
    parent->numChilds ++;

    return child;
}

int max(int a, int b, int c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int countPathLength(Node *node)
{
    int i, sumChildsPath = 0, childs = 0;
    Node *child;

    for (i = 0; i < TABLE_SIZE; i ++)
    {
        child = node->childs->table[i];

        while (child != NULL)
        {
            childs ++;
            sumChildsPath += countPathLength(child);  // <node_file> + "/" + <child_file>
            child = child->next;
        }
    }

    node->pathLength = (node->fileLength) * (int)fmax(1, node->numLeafs) + sumChildsPath + node->numLeafs;

    if (node->parent)
    {
        node->parent->numLeafs += max(node->numLeafs, childs, 1);
        node->parent->childsPathLength += node->pathLength;
    }

    return node->pathLength;
}

void find_shortest_catalog_path(Node *node, int *menor, int N, Node **new_root)
{
    if (node->numChilds == 0) // nao eh uma pasta ou eh a raiz
        return;

    int i;
    Node *parent = node->parent;
    if (parent)
    {
        node->othersPathLength = parent->othersPathLength  // caminho total dos demais arquivos
                                + parent->childsPathLength - node->pathLength  // caminhos dos demais arquivos de parent
                                + 3 * (N - node->numLeafs); // strlen("../") + (quantidade de arquivos fora desse 'galho')
        
        node->pathLengthAsRoot = node->childsPathLength // caminho dos arquivos nessa pasta
                                + node->othersPathLength; // caminho dos demais arquivos
    }
    else
    {
        node->pathLengthAsRoot = node->childsPathLength;
    }

    debug printf("node: %s, pathAsRoot = %d\n", node->file, node->pathLengthAsRoot); /*debug*/
    if (node->pathLengthAsRoot < *menor)
    {
        *menor = node->pathLengthAsRoot;
        *new_root = node;
    }
    
    Node *child;
    for (i = 0; i < TABLE_SIZE; i ++)
    {
        child = node->childs->table[i];
        while (child)
        {
            find_shortest_catalog_path(child, menor, N, new_root);
            child = child->next;
        }
    }
}

int count_childs(Node *node)
{
    int i, childs = 0;
    Node *child;
    for (i = 0; i < TABLE_SIZE; i ++)
    {
        child = node->childs->table[i];
        while (child)
        {
            childs ++;
            child = child->next;
        }
    }
    return childs;
}

void print_childs(Node *node)
{ // funcao para debug. imprime os filhos de um no
    Node *sibling;
    for (int i = 0; i < TABLE_SIZE; i ++)
    {
        sibling = node->childs->table[i];
        printf("[%d: ", i);
        if (sibling == NULL)
            printf("0");
        debug printf("i = %d: %p\n", i, sibling); /*debug*/
        while (sibling != NULL)
        {
            printf("%s", sibling->file);
            sibling = sibling->next;
            if (sibling)
                printf(", ");
        }
        printf("]%s", i < TABLE_SIZE - 1 ? "," : "");
    }
    printf("\n");
}

void dump_files(Node *parent, char *caminho, int len)
{ // funcao para debug. imprime o caminho completo de todos os arquivos
    printf("\n");
    printf("> dumping \"%s\": leafs = %d\n", caminho, parent->numLeafs);
    printf("pathLength = %d\n", parent->pathLength);
    printf("childsPathLength = %d\n", parent->childsPathLength);
    printf("childs: ");
    print_childs(parent);
    
    for (int i = 0; i < TABLE_SIZE; i ++)
    {
        Node *child = parent->childs->table[i];
        while (child != NULL)
        {
            if (count_childs(child) == 0)  // eh uma folha
            {
                printf("caminho: %s/%s : pathLength = %d\n", caminho, child->file, child->pathLength);
            }
            else
            {
                int new_len = len + 1 + child->pathLength;
                char new_caminho[new_len + 1];
                snprintf(new_caminho, new_len + 1, "%s/%s", caminho, child->file);
                dump_files(child, new_caminho, new_len);
            }
            child = child->next;
        }
    }
}

void adicionarArquivo(Node *node, char *caminho)
{ // adiciona um novo arquivo no sistema
    Node *parent = node;
    char * file = strtok(caminho, "/");
    while (file != NULL)
    {
        parent = add_child(parent, file);
        file = strtok(NULL, "/");
    }
}

void free_node(Node *node)
{
    if (node)
    {
        free(node->file);
        for (int i = 0; i < TABLE_SIZE; i++)
            free_node(node->childs->table[i]);
        free(node->childs->table);
        free(node->childs);
        free(node);
    }
}

void free_file(File *file)
{
    if (file)
    {
        free_node(file->root);
        free(file);
    }
}

int main()
{
    int N, i, ans;
    char caminho[MAX_LEN_CAMINHO] = "";
    File * files = create_file();

    char enderecoCompleto[MAX_LEN_CAMINHO];

    scanf("%d", &N);

    for (i = 0; i < N; i ++)
    {
        scanf(" %s", enderecoCompleto);
        adicionarArquivo(files->root, enderecoCompleto);
    }

    countPathLength(files->root);

    debug printf("dump_start\n");
    debug dump_files(files->root, caminho, files->root->pathLength);
    debug printf("dump_end\n");

    debug printf("-----------------------------");
    debug printf("\nchilds = %d, size = %d, leafs = %d\n", count_childs(files->root), files->root->childsPathLength, files->root->numLeafs);

    Node *new_root = files->root;
    ans = files->root->childsPathLength;
    debug printf("shortest_path:\n");
    find_shortest_catalog_path(files->root, &ans, N, &new_root);

    printf("%d\n", ans);
    debug printf("new_root = [%s]\n", new_root->file);

    free_file(files);

    return 0;
}
