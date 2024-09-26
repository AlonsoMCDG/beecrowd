// bee 2338 - Morse
// Alonso Martins
// 26/09/2024
#include <stdio.h>
#include <string.h>
#define DEBUG 0
#define debug if (DEBUG)

enum separator
{
    SIMBOLO = 1,
    LETRA = 3,
    PALAVRA = 7
};

int get_separador(char *s, int p)
{
    debug printf("get_separator in index %d\n", p);
    debug printf("s[%d] = %c\n", p, s[p]);
    int cont = 0;
    
    while (s[p + cont] == '.')
        cont ++;

    debug printf("cont = %d\n", cont);
    return cont ? cont : LETRA;
}

int main()
{
    char tabela_morse[32] = "-temaniowkugrds-jy-q-xv-pcfzlbh";
    char codigo[1002];
    int N, i, j;

    scanf("%d", &N);

    while (N -- && scanf(" %s", codigo))
    {
        int pot[4] = {};
        int sz = strlen(codigo);
        int cont = 0, qtd_simbolos = 0;
        int separador;

        for (i = 0; i <= sz; i ++)
        {
            if (codigo[i] == '.' || codigo[i] == '\0')
            {
                separador = get_separador(codigo, i);

                pot[qtd_simbolos] = (cont % 3) + qtd_simbolos;
                debug printf("novo simbolo > cont = %d, pot[%d] = %d\n", cont, qtd_simbolos, pot[qtd_simbolos]);
                qtd_simbolos ++;

                if (separador == LETRA || separador == PALAVRA)
                {
                    int letra = 0;

                    debug printf("pot = [");
                    for (j = 0; j < qtd_simbolos; j ++)
                    {
                        debug printf(" %d", pot[j]);
                        letra += 1 << (pot[j]);
                    }
                    debug printf(" ]\n");
                    
                    debug printf("SAIDA[");
                    printf("%c", tabela_morse[letra]);
                    debug printf("]\n");

                    memset(pot, 0, sizeof(pot));
                    qtd_simbolos = 0;
                }

                if (separador == PALAVRA)
                {
                    debug printf("SAIDA[");
                    printf(" ");
                    debug printf("]\n");
                }
                else if (separador == LETRA || separador == SIMBOLO)
                {
                }
                else
                {
                    printf("OPA!!! Algo de errado nao esta certo.\n");
                    printf("separador=%d (i=%d)\n", separador, i);
                    return 0;
                }

                i += separador - 1;
                cont = 0;
            }
            else
            {
                cont ++;
            }
        }
        printf("\n");
    }

    return 0;
}


// -----------
// === -> 0
// =   -> 1
// -----------
// T ===             : 2^(0+0) = 1
// E =               : 2^(1+0) = 2
// M === ===         : 2^(0+0) + 2^(0+1) = 1 + 2 = 3
// A = ===           : 2^(1+0) + 2^(0+1) = 2 + 2 = 4
// N === =           : 2^(0+0) + 2^(1+1) = 1 + 4 = 5
// I = =             : 2^(1+0) + 2^(1+1) = 2 + 4 = 6
// O === === ===     : 2^(0+0) + 2^(0+1) + 2^(0+2) = 1 + 2 + 4 = 7
// W = === ===       : 2^(1+0) + 2^(0+1) + 2^(0+2) = 2 + 2 + 4 = 8
// K === = ===       : 2^(0+0) + 2^(1+1) + 2^(0+2) = 1 + 4 + 4 = 9
// U = = ===         : 2^(1+0) + 2^(1+1) + 2^(0+2) = 2 + 4 + 4 = 10
// G === === =       : 2^(0+0) + 2^(0+1) + 2^(1+2) = 1 + 2 + 8 = 11
// R = === =         : 2^(1+0) + 2^(0+1) + 2^(1+2) = 2 + 2 + 8 = 12
// D === = =         : 2^(0+0) + 2^(1+1) + 2^(1+2) = 1 + 4 + 8 = 13
// S = = =           : 2^(1+0) + 2^(1+1) + 2^(1+2) = 2 + 4 + 8 = 14
//   === === === === : 2^(0+0) + 2^(0+1) + 2^(0+2) + 2^(0+3) = 1 + 2 + 4 + 8 = 15
// J = === === ===   : 2^(1+0) + 2^(0+1) + 2^(0+2) + 2^(0+3) = 2 + 2 + 4 + 8 = 16
// Y === = === ===   : 17
//   = = === ===     : 18
// Q === === = ===   : 19
//   = === = ===     : 20
// X === = = ===     : 21
// V = = = ===       : 22
//   === === === =   : 23
// P = === === =     : 24
// C === = === =     : 25
// F = = === =       : 26
// Z === === = =     : 27
// L = === = =       : 28
// B === = = =       : 29
// H = = = =         : 30
  
