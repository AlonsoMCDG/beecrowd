// bee 1769 - CPF 1
// Alonso Martins
// 02/07/2024
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define ctoi(x) (x - '0')

int main()
{
    char cpf[20];
    
    while (scanf(" %s", cpf) != EOF)
    {
        int b1 = 0, b2 = 0, i, t = 1;
        for (i = 0; i < 11; i ++)
            if (isdigit(cpf[i]))
                b1 += ctoi(cpf[i]) * t,
                b2 += ctoi(cpf[i]) * (10 - t),
                t ++;

        b1 = (b1 % 11) % 10;
        b2 = (b2 % 11) % 10;

        if (b1 == ctoi(cpf[12]) && b2 == ctoi(cpf[13]))
            printf("CPF valido\n");
        else
            printf("CPF invalido\n");
    }

    return 0;
}
