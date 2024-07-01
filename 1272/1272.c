// bee 1272 - Mensagem Oculta
// Alonso Martins
// 30/06/2024
#include <stdio.h>

int main()
{
    int N, t;

    scanf("%d%*c", &N);

    while (N --)
    {
        char c0 = ' ', c1;
        char msg[52] = "";
        t = 0;

        while ((c1 = getchar()) != '\n')
        {
            if (c0 == ' ' && c1 != ' ')
                msg[t ++] = c1;

            c0 = c1;
        }

        msg[t] = '\0';

        printf("%s\n", msg);
    }

    return 0;
}
