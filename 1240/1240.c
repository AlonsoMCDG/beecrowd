// bee 1240 - Encaixa ou Nao I
// Alonso Martins
// 29/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, sz1, sz2; 
    char n1[12], n2[12];
    scanf("%d", &N);

    while (N -- && scanf(" %s %s", n1, n2))
    {
        sz1 = strlen(n1), sz2 = strlen(n2);

        if (sz2 > sz1 || strcmp(&n1[sz1 - sz2], n2))
            printf("nao encaixa\n");
        else
            printf("encaixa\n");
    }

    return 0;
}
