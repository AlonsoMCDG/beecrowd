// bee 1317 - Eu Odeio SPAM, Mas Algumas Pessoas Amam
// Alonso Martins
// 29/09/2024
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Pessoa
{
    char nome[22];
    int nivelSpam[100];
    int numAmigos;
    int amigos[20];
} Pessoa;

typedef struct Spam
{
    int origem;
    char atributos[3][22];
    int t1, t2;
} Spam;

void send_spam(int id_spam, int id_pessoa, Pessoa **pessoas, bool *ja_recebeu)
{
    if (ja_recebeu[id_pessoa])
        return;

    int i = 0;
    ja_recebeu[id_pessoa] = true;
    pessoas[id_pessoa]->nivelSpam[id_spam] = pessoas[id_pessoa]->numAmigos;

    for (i = 0; i < pessoas[id_pessoa]->numAmigos; i ++)
        send_spam(id_spam, pessoas[id_pessoa]->amigos[i], pessoas, ja_recebeu);
}

int main()
{
    int N, i, j, amigo, origem, totalSpams = 0;
    Pessoa **p = malloc(20 * sizeof(Pessoa *));
    Spam spams[100];

    for (i = 0; i < 20; i ++) p[i] = malloc(sizeof(Pessoa));

    while(scanf("%d", &N), N)
    {
        // emais dos amigos
        for (i = 0; j = 0, i < N; i ++)
        {
            while (scanf("%d", &amigo), amigo)
                p[i]->amigos[j ++] = amigo - 1;

            memset(p[i]->nivelSpam, 0, 100 * sizeof(int));
            p[i]->numAmigos = j;
        }
        
        // descricoes do SPAM
        totalSpams = 0;
        while (scanf("%d", &origem), origem)
        {
            spams[totalSpams].origem = origem - 1;
            scanf("%d %d", &spams[totalSpams].t1, &spams[totalSpams].t2);

            for (j = 0; j < 3; j ++)
                scanf(" %s", spams[totalSpams].atributos[j]);

            totalSpams ++;
        }

        // nome de cada pessoa
        for (i = 0; i < N; i ++)
            scanf(" %s", p[i]->nome);

        for (i = 0; i < totalSpams; i ++)
        {
            bool ja_recebeu[20] = {};
            origem = spams[i].origem;

            send_spam(i, origem, p, ja_recebeu);
        }

        for (i = 0; i < N; i ++)
        {
            printf("%s: ", p[i]->nome);
            for (j = 0; j < totalSpams; j ++)
            {
                int ns = p[i]->nivelSpam[j];
                int attr = (ns >= spams[j].t1) + (ns >= spams[j].t2);
                printf("%s ", spams[j].atributos[attr]);   
            }
            printf("\n");
        }
    }

    return 0;
}
