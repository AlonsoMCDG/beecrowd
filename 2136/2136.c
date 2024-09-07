// bee 2136 - Amigos do Habay
// Alonso Martins
// 06/09/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

typedef struct Pessoa
{
    char nome[30];
    int len_nome;
    int escolha;
} Pessoa;

typedef struct Set
{
    Pessoa pessoas[TABLE_SIZE][20];
    int size[TABLE_SIZE];
} Set;

unsigned int hash(unsigned char *str)
{
    unsigned int hash = 5387;
    int c;

    while ((c = *str ++))
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

int insert(Set *set, char *nome, char *op)
{
    unsigned int index = hash(nome), i;

    for (i = 0; i < set->size[index]; i ++)
        if (strcmp(set->pessoas[index][i].nome, nome) == 0)
            return 0; // a pessoa ja esta na lista
    
    strcpy(set->pessoas[index][set->size[index] ++].nome, nome);
    return 1; // nova pessoa adicionada aa lista
}

int comp(const void *a, const void *b)
{
    Pessoa *A = (Pessoa *)a, *B = (Pessoa *)b;

    if (B->escolha - A->escolha) // ordena por "YES" (1) e depois "NO" (0)
        return B->escolha - A->escolha;

    return strcmp(A->nome, B->nome); // ordena alfabeticamente
}

int main()
{
    char nome[30], opcao[5], amigo_te_Habay[30] = "";
    Set set; memset(set.size, 0, sizeof(set.size));
    Pessoa participantes[10000];
    int qtd_participantes = 0, i, ordem_inscricao = 0;
    int len_nome_amigo_Habay = 0, ordem_inscricao_amigo = 0;

    while (scanf(" %s", participantes[qtd_participantes].nome), strcmp(participantes[qtd_participantes].nome, "FIM"))
    {
        scanf(" %s", opcao);
        
        // checa se eh uma nova inscricao ou nao
        if (insert(&set, participantes[qtd_participantes].nome, opcao))
        {
            participantes[qtd_participantes].escolha = (opcao[0] == 'Y');
            int lenp = strlen(participantes[qtd_participantes].nome);
            participantes[qtd_participantes].len_nome = lenp;
            ordem_inscricao ++;

            if (opcao[0] == 'Y' && lenp >= len_nome_amigo_Habay)
                if (lenp > len_nome_amigo_Habay || ordem_inscricao < ordem_inscricao_amigo)
                {
                    strcpy(amigo_te_Habay, participantes[qtd_participantes].nome);
                    ordem_inscricao_amigo = ordem_inscricao;
                    len_nome_amigo_Habay = lenp;
                }

            qtd_participantes ++;
        }
    }

    qsort(participantes, qtd_participantes, sizeof(participantes[0]), comp);

    for (i = 0; i < qtd_participantes; i ++)
        printf("%s\n", participantes[i].nome);//, participantes[i].escolha ? "YES" : "NO");
    
    printf("\nAmigo do Habay:\n%s\n", amigo_te_Habay);

    return 0;
}
