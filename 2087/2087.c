// bee 2087 - Conjuntos Bons e Ruins
// Alonso Martins
// 26/04/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_EH_VALIDA 0
#define STRING_TEM_PREFIXO 1
#define STRING_EH_PREFIXO 2
#define STRING_IDENTICA 3
#define MAX_LENGTH_PALAVRA 102
#define MAX_NODES 26

typedef struct
{
    int next[MAX_NODES]; // [0-25]: proxima letra
} Node;

typedef struct
{
    int root[MAX_NODES];
    // Node *nodes[MAX_LENGTH_PALAVRA]; // [0-25]: letras na camada atual
    Node nodes[MAX_LENGTH_PALAVRA][MAX_NODES]; // [0-25]: letras na camada atual
} Tree;

void guardar(Tree *t, char *s);
void printTree(Tree *t, int n);
void zerarTree(Tree *t);
void initTree(Tree *t);
int validar(Tree *t, char *s);
int sum(int v[MAX_NODES]);
void liberarMemoria(Tree *t);

int main() 
{
    int N, i, j, k;
    char palavra[102];
    char *ans;

    // Tree *tree;
    // tree = (Tree *)malloc(sizeof(Tree));

    // initTree(tree); // aloca a memoria necessaria para a arvore

    Tree tree;
    
    // testando as funcoes:
    // guardar(&tree, "alonso");
    // guardar(&tree, "monstro");
    // guardar(&tree, "ostra");

    // printf("sum(root) = %d\n", sum(&tree.root));

    // printTree(&tree, MAX_LENGTH_PALAVRA);
    
    // printf("search: \"%s\" = %d\n", "alonso", validar(&tree, "alonso"));
    // printf("search: \"%s\" = %d\n", "a", validar(&tree, "a"));
    // printf("search: \"%s\" = %d\n", "balde", validar(&tree, "balde"));
    // printf("search: \"%s\" = %d\n", "alonsos", validar(&tree, "alonsos"));

    // printf("Fim\n");

    // printTree(&tree, 10);

    // return 0;
    
    while (scanf("%d", &N) && N) 
    {
        getchar();
        
        zerarTree(&tree); // limpa as posicoes da arvore para a proxima execucao

        ans = "Conjunto Bom";  // assume inicialmente que o conjunto eh bom
        
        // int maxLen = 1;
        // printf("Conjunto:\n");
        for (i = 0; i < N; i ++) 
        {
            fgets(palavra, sizeof(palavra), stdin);  // faz a leitura da palavra
            palavra[strlen(palavra) - 1] = '\0'; // remove o '\n' no fim da string

            // maxLen = maxLen >= strlen(palavra) ? maxLen : strlen(palavra);
            
            // printf("%s - ", palavra);
            int teste = validar(&tree, palavra);  // testa se eh uma palavra valida para o conjunto continuar bom
            // switch (teste)
            // {
            //     case STRING_EH_VALIDA: printf("valida\n"); break;
            //     case STRING_EH_PREFIXO: printf("eh prefixo\n"); break;
            //     case STRING_TEM_PREFIXO: printf("tem prefixo\n"); break;
            //     case STRING_IDENTICA: printf("ja guardada\n"); break;
            //     default: break;
            // }

            // if (validar(tree, palavra) != STRING_EH_VALIDA)
            if (teste != STRING_EH_VALIDA)  // se nao for uma palavra valida
                ans = "Conjunto Ruim";      // define que o conjunto eh ruim

            if (ans[9] != 'R') // nao guarda mais palavras se o conjunto ja eh ruim
                guardar(&tree, palavra);
        }
        // printf("\n");

        printf("%s\n", ans);    // imprime a resposta - (Conjunto Ruim/Bom)

        // printf("\n\ntree:\n");
        // printTree(tree, maxLen);
        // printf("\n\n\n\n");
    }

    // liberarMemoria(tree);

    return 0;
}

void zerarPosicoes(int v[MAX_NODES])
{
    int i;
    for (i = 0; i < MAX_NODES; i ++)    // percorre o vetor
        v[i] = 0;   // e define as posicoes para o valor 0
}

void zerarTree(Tree *t) // zera as posicoes pra limpar o lixo na memoria alocada
{
    int i, j;

    zerarPosicoes(t->root); 

    for (i = 0; i < MAX_LENGTH_PALAVRA; i ++)
        for (j = 0; j < MAX_NODES; j ++)
            zerarPosicoes(t->nodes[i][j].next);
    
}

/*
void initTree(Tree *t)  // funcao nao usada
{
    int i, j;

    // t->root = (int *)malloc(MAX_NODES * sizeof(int));
    // memset(t->root, 0, MAX_NODES);

    for (i = 0; i < MAX_LENGTH_PALAVRA; i ++)
    {
        // t->nodes[i] = (Node *)calloc(MAX_NODES, sizeof(Node));
        // t->nodes[i] = (Node *)malloc(MAX_NODES * sizeof(Node));
        
        for (j = 0; j < MAX_NODES; j ++)
        {
            // t->nodes[i][j].next = (int *)malloc(MAX_NODES * sizeof(int));
            // memset(t->nodes[i][j].next, 0, MAX_NODES);
            zerarPosicoes(t->nodes[i][j].next);
        }
    }

    zerarTree(t);
}

void liberarMemoria(Tree *t)
{
    int i, j, k;

    for (i = 0; i < MAX_LENGTH_PALAVRA; i ++)
        free(t->nodes[i]);

    free(t);
} //*/

void guardar(Tree *t, char *s)  // guarda a string s na arvore t
{
    int len = strlen(s);
    int i, j;
    char c = s[0] - 'a';    // caractere atual
    char nxtc;              // caractere na proxima camada

    t->root[c] = 1;     // cria uma nova raiz para a palavra s

    for (i = 0; i < len - 1; i ++)
    {
        nxtc = s[i + 1] - 'a';
        t->nodes[i][c].next[nxtc] = 1;  // marca que eh possivel chegar em nxct a partir de c na camada i
        c = nxtc;   // define o proximo caractere para a iteracao seguinte do loop
    }
}

int sum(int v[MAX_NODES]) // soma os valores guardados no vetor
{
    int i, soma = 0;
    for (i = 0; i < MAX_NODES; i ++)
        soma += v[i];
    return soma;
}

int validar(Tree *t, char *s) // procura e checa se s eh uma string valida para o conjunto
{
    int len = strlen(s);
    int i, j;
    char c = s[0] - 'a';
    char nxtc;
    // int saida = STRING_EH_VALIDA;  // assume inicialmente que a string s eh valida
    int matches = 0;    // quantidade das letras iniciais encontradas na arvore

    if (!t->root[c])    // nenhuma outra palavra inicia com o primeiro caractere da string s
        return STRING_EH_VALIDA; // entao eh uma string valida

    matches ++; // pelo menos o primeiro caractere de s já está guardado

    for (i = 0; i < len - 1; i ++)
    {
        nxtc = s[i + 1] - 'a';  // obtem o caractere seguinte da string

        if (!t->nodes[i][c].next[nxtc]) // checa se nao eh possivel ir para nxtc a partir de c na camada i
            if (sum(t->nodes[i][c].next)) // se nao for, checa se a palavra guardada continua com alguma outra letra
                return STRING_EH_VALIDA; // se sim, a string s eh diferente e eh valida
            else 
                return STRING_TEM_PREFIXO; // senao, a string guardada eh prefixo de s
        
        matches ++; // foi possivel, entao encontrou mais uma letra da string

        c = nxtc;   // define o proximo caractere
    }
    // chegou no fim da string s, entao basta checar se ela eh prefixo da string guardada
    // (checagem desnecessaria, a esse ponto a string s já nao eh uma string válida)
    if (sum(t->nodes[i][c].next)) // se a string guardada continua, s eh prefixo dela
        return STRING_EH_PREFIXO;
    else    // senao, as duas strings sao identicas
        return STRING_IDENTICA;
}

void imprimeHeaderLetras()
{
    int k;
    printf("           ");
    for (k = 0; k < 26; k ++)
        printf(" %2c", 'a'+k);
    printf("\n");
}

void printTree(Tree *t, int n)
{
    int i, j, k;

    printf("Tree:\n");

    imprimeHeaderLetras();
    printf("%10s: ", "Root");

    for (i = 0; i < 26; i ++)
        printf(t->root[i] ? "%2d " : "-- ", t->root[i]);
    printf("\n\n");

    for (i = 0; i < n; i ++)
    {
        printf("Linha %d: %p\n", i, t->nodes[i]);

        imprimeHeaderLetras();
            
        for (j = 0; j < 26; j ++)
        {
            
            printf("> Letra %2c: ", 'a'+j);
            for (k = 0; k < 26; k ++)
            {
                printf(t->nodes[i][j].next[k] ? "%2d " : "-- ", t->nodes[i][j].next[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}


// void printVet(int *v)
// {
//     for (int i = 0; i < 26; i ++)
//         printf("%2d ", v[i]);
//     printf("\n");
// }
// void printMat(int *m[26])
// {
//     for (int i = 0; i < 26; i ++)
//         printf("%2c ", 'a'+i);
//     printf("\n");
//     for (int i = 0; i < 26; i ++)
//     {
//         for (int j = 0; j < 26; j ++)
//             printf("%2d ", m[i][j]);
//         printf("\n");
//     }
// }
