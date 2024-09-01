// bee 2662 - Escala Musical
// Alonso Martins
// 01/09/2024
#include <stdio.h>
#include <stdlib.h>

// // converte `n` para binario
// void tobin(unsigned n)
// {
//     char b[33] = "00000000000000000000000000000000";
//     unsigned i = 0, a = n;
//     while (a)
//     {
//         b[i ++] = (a & 1) + '0';
//         a >>= 1;
//     }
//     printf("%4d = %s\n", n, b);
// }

int main()
{
    int N, i, j, nota, achou;
    char *escalas_txt[13] =    { "do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si", "desafinado"};
    unsigned escalas_num[12] = { 2741,  1387, 2774,  1453, 2906, 1717,  3434,  2773,   1451, 2902,  1709, 3418 };
    unsigned musica = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i ++)
    {
        scanf("%d", &nota);

        // converte `nota` para um numero entre 0 e 11 -> [(nota - 1) % 12]
        // e muda o bit nesse posicao de `musica` para 1
        musica = (1 << (-- nota % 12)) | musica;
    }

    // para cada escala, testa se a musica esta nesta escala `i` (0=do, ..., 11=si)
    for (i = 0; i < 12; i ++)
    {
        // supoe que a escala atual eh a qual a musica esta
        achou = 1;

        // testa se as notas da musica estao dentro das notas da escala
        for (j = 0; j < 12; j ++)
        {
            if (((1 << j) & musica) && !((1 << j) & escalas_num[i]))
            {
                // a nota `j` (0=do, ..., 11=si) da musica esta fora da escala
                achou = 0;
                break;
            }
        }

        // se achou a escala da musica, pare
        if (achou) break;
    }

    printf("%s\n", escalas_txt[i]);

    return 0;
}

/*
C  C# D  D# E  F  F# G  G# A  A# B
1  2  3  4  5  6  7  8  9  10 11 12
13 14 15 16 17 18 19 20 21 22 23 24


dist: 2 2 1 2 2 2 1
do  :[1]- 3 - 5 6 - 8 - 10 -- 12 
do# : 1[2]- 4 - 6 7 - 9 -- 11 -- 
re  : - 2[3]- 5 - 7 8 - 10 -- 12 
re# : 1 - 3[4]- 6 - 8 9 -- 11 -- 
mi  : - 2 - 4[5]- 7 - 9 10 -- 12 
fa  : 1 - 3 - 5[6]- 8 - 10 11 -- 
fa# : - 2 - 4 - 6[7]- 9 -- 11 12 
sol : 1 - 3 - 5 - 7[8]- 10 -- 12 
sol#: 1 2 - 4 - 6 - 8[9]-- 11 -- 
la  : - 2 3 - 5 - 7 - 9[10]-- 12 
la# : 1 - 3 4 - 6 - 8 - 10[11]-- 
si  : - 2 - 4 5 - 7 - 9 -- 11[12]


fa# : - 2 - 4 - 6[7]- 9 -- 11 12 
si  : - 2 - 4 5 - 7 - 9 -- 11[12]
mi  : - 2 - 4[5]- 7 - 9 10 -- 12 
la  : - 2 3 - 5 - 7 - 9[10]-- 12 
re  : - 2[3]- 5 - 7 8 - 10 -- 12 
sol : 1 - 3 - 5 - 7[8]- 10 -- 12 
do  :[1]- 3 - 5 6 - 8 - 10 -- 12 
fa  : 1 - 3 - 5[6]- 8 - 10 11 -- 
la# : 1 - 3 4 - 6 - 8 - 10[11]-- 
re# : 1 - 3[4]- 6 - 8 9 -- 11 -- 
sol#: 1 2 - 4 - 6 - 8[9]-- 11 -- 
do# : 1[2]- 4 - 6 7 - 9 -- 11 -- 



*/
