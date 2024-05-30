// bee 1876 - Rabiola
// Alonso Martins
// 30/05/2024
#include <stdio.h>
#include <string.h>

int maior(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char cipo[102], *c;

    while (scanf(" %s", cipo) != EOF)
    {
        int i, sz = strlen(cipo);
        int maiorFilete, f1, f2, f3;

        maiorFilete = f1 = strcspn(cipo, "x");
        i = f1 + 1;
        while (i < sz)
        {
            f2 = strcspn(&cipo[i], "x");
            maiorFilete = maior(maiorFilete, f2 / 2);
            i += f2 + 1;
        }
        c = strrchr(cipo, 'x');
        f3 = (c == NULL ? 0 : strlen(c) - 1);
        maiorFilete = maior(maiorFilete, f3);

        printf("%d\n", maiorFilete);
    }

    return 0;
}
