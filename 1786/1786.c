// bee 1786 - CPF 2
// Alonso Martins
// 10/07/2024
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define ctoi(x) (x - '0')

int main()
{
    char cpf[20], out[20];
    
    while (scanf(" %s", cpf) != EOF)
    {
        int b1 = 0, b2 = 0, i, j, t = 1;
        for (i = 0; i < 11; i ++)
            if (isdigit(cpf[i]))
                b1 += ctoi(cpf[i]) * t,
                b2 += ctoi(cpf[i]) * (10 - t),
                t ++;

        b1 = (b1 % 11) % 10;
        b2 = (b2 % 11) % 10;

        for (i = j = 0; i < 9; i ++)
        {
            if (i && !(i % 3))
                out[j ++] = '.';
            out[j ++] = cpf[i];
        }
        out[j] = '\0';
        printf("%s-%d%d\n", out, b1, b2);
    }

    return 0;
}
