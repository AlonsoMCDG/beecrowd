// bee 1192 - O jogo Matematico de Paula
// Alonso Martins
// 21/05/2024
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int N, A, B; scanf("%d", &N);
    char n[5];

    while (N -- && scanf(" %s", n))
    {
        A = atoi(&n[0]), B = atoi(&n[2]);

        if (A == B)
            printf("%d\n", A * B);
        else if (isupper(n[1]))
            printf("%d\n", B - A);
        else
            printf("%d\n", A + B);
    }

    return 0;
}
