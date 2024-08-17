// bee 2484 - Abracadabra
// Alonso Martins
// 17/08/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int i, sz;
    char s[102], palavra[204];

    while (scanf(" %s", s) != EOF)
    {
        for (i = 0, sz = strlen(s); i < sz; i ++)
        {
            palavra[2 * i] = s[i];
            palavra[2 * i + 1] = ' ';
        }

        palavra[sz * 2 - 1] = '\0';
        strcpy(s, "");

        for (i = 0; i < sz; i ++)
        {
            printf("%s%s\n", s, palavra);
            s[i] = ' ', s[i + 1] = '\0';
            palavra[2 * (sz - i - 1) - 1] = '\0';
        }
        printf("\n");
    }

    return 0;
}
