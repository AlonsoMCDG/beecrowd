// bee 1357 - Em Braille
// Alonso Martins
// 04/06/2024
#include <stdio.h>

#define ctoi(x) (x-'0')

char digitosEmBraile[10][3][3] = {
    {".*", "**", ".."}, // 0 : 0248 = 14
    {"*.", "..", ".."}, // 1 : 1000 = 1
    {"*.", "*.", ".."}, // 2 : 1040 = 5
    {"**", "..", ".."}, // 3 : 1200 = 3
    {"**", ".*", ".."}, // 4 : 1208 = 11
    {"*.", ".*", ".."}, // 5 : 1008 = 9
    {"**", "*.", ".."}, // 6 : 1240 = 7
    {"**", "**", ".."}, // 7 : 1248 = 15
    {"*.", "**", ".."}, // 8 : 1048 = 13
    {".*", "*.", ".."}  // 9 : 0240 = 6
};

int braileEmDigitos[] = {0, 1, 0, 3, 0, 2, 9, 6, 0, 5, 0, 4, 0, 8, 0, 7};

void imprimeDigitosParaBraile(char *s, int N)
{
    int i, j, k, t;
    char out[300];
    for (k = 0; k < 3; k ++, 0, out[-- t] = '\0', printf("%s\n", out))
        for (t = i = 0; i < N; i ++, out[t ++] = ' ')
            for (j = 0; j < 2; j ++)
                out[t ++] = digitosEmBraile[ctoi(s[i])][k][j];
}

void imprimeBraileParaDigitos(char s[100][3][3], int N)
{
    int i, j, k, digito, peso;

    for (i = 0; digito = 0, peso = 1, i < N; i ++)
    {   
        for (k = 0; k < 2; k ++)
            for (j = 0; j < 2; j ++, peso *= 2)
                digito += peso * (s[i][k][j] == '*');
        printf("%d", braileEmDigitos[digito]);
    }
    printf("\n");
}

int main()
{

    int D, i, j, k;
    char op;
    char inputS[102];
    char inputB[100][3][3];

    while (scanf("%d", &D), D)
    {
        scanf(" %c", &op);

        switch (op)
        {
            case 'S':
                scanf("%s%*c", inputS);
                imprimeDigitosParaBraile(inputS, D);
                break;

            case 'B':
                for (k = 0; k < 3; k ++)
                    for (i = 0; i < D; i ++)
                        scanf("%s", inputB[i][k]);

                imprimeBraileParaDigitos(inputB, D);
                break;
        }
    }

    return 0;
}
