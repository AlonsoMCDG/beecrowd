// bee 1763 - Tradutor do Papai Noel
// Alonso Martins
// 08/08/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 24

typedef struct Frase
{
    char * pais;
    char * traducao;
} Frase;

typedef struct HashTable
{
    Frase frases[TABLE_SIZE][5];
    short size[TABLE_SIZE];
} HashTable;

// função hash
unsigned int hash(unsigned char *str)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

HashTable * new_hashtable()
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    int i;

    for (i = 0; i < TABLE_SIZE; i ++)
    {
        ht->size[i] = 0;
    }

    return ht;
}

void insert(HashTable *ht, char *pais, char *traducao)
{
    unsigned int index = hash(pais);
    short sz = ht->size[index] ++;

    ht->frases[index][sz].pais = pais;
    ht->frases[index][sz].traducao = traducao;
}

char *get_feliz_natal(HashTable *ht, char *pais)
{
    unsigned int index = hash(pais);
    short i;

    for (i = 0; i < ht->size[index]; i ++)
        if (strcmp(ht->frases[index][i].pais, pais) == 0)
            return ht->frases[index][i].traducao;

    return "--- NOT FOUND ---";
}

int main()
{
    HashTable *hashtable = new_hashtable();
    char pais[30], *dados[24][2] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"},
    };
    int i;

    for (i = 0; i < 24; i ++)
        insert(hashtable, dados[i][0], dados[i][1]);

    while (scanf(" %s", pais) != EOF)
    {
        printf("%s\n", get_feliz_natal(hashtable, pais));
    }

    return 0;
}
