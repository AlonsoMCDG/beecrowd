// bee 1263 - Aliteracao
// Alonso Martins
// 23/06/2024
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *p, frase[5002], prev;
    int ans, cont;

    while (scanf("%5001[^\n]%*c", frase) != EOF)
    {
        prev = 1;
        ans = 0;
        p = strtok(frase, " ");

        while (p != NULL)
        {
            if (tolower(p[0]) != prev) cont = 0;
            else cont ++;

            ans += (cont == 1);
            prev = tolower(p[0]);

            p = strtok(NULL, " ");
        }

        printf("%d\n", ans);
    }

    return 0;
}
