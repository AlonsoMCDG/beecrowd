// bee 2815 - Digitador Gago
// Alonso Martins
// 18/05/2024
#include <stdio.h>
#include <string.h>

int gaguejou(char *p)
{
    return !strncmp(&p[0], &p[2], 2);
}

int main()
{
    char palavra[20];
    int flag = 0; // para saber se uma palavra ja foi impressa

    while (scanf("%s", palavra) != EOF)
    {
        if (flag ++) printf(" ");

        if (strlen(palavra) < 4 || !gaguejou(palavra))
        {
            printf("%s", palavra);
            continue;
        }
        printf("%s", &palavra[2]); // gaguejou
    }
    printf("\n");

    return 0;
}
