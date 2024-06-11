// bee 2906 - Database of Clients
// Alonso Martins
// 10/06/2024
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char email[102];
    char localpart[102];
    char provider[102];
} email;

void formatar(char *s)
{
    int i, j, flag = 0, sz = strlen(s);
    for (j = i = 0; j < sz; j ++)
    {
        flag = flag || s[j] == '@';

        if (!flag && s[j] == '.')
            continue;

        if (s[j] == '+' && (flag = 1))
            while (j < sz && s[j] != '@')
                j ++;

        s[i ++] = s[j];
    }
    s[i] = '\0';
}

int procurarEmail(email *db, int size, char *email)
{   
    int i;
    for (i = 0; i < size; i ++)
        if (strcmp(db[i].email, email) == 0)
            return 1;
    return 0;
}

int main()
{   
    int N, i, size = 0,  at;
    scanf("%d", &N);
    email database[N];
    char email[102];

    for (i = 0; i < N; i ++)
    {
        scanf(" %s", email);

        formatar(email);

        if (procurarEmail(database, size, email) == 0)
        {
            strcpy(database[size].email, email);

            email[at = strcspn(email, "@")] = '\0';

            strcpy(database[size].localpart, email);
            strcpy(database[size].provider, &email[at + 1]);

            size ++;
        }
    }

    printf("%d\n", size);
    return 0;
}
