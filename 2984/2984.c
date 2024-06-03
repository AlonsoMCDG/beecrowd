// bee 2984 - Assuntos Pendentes
// Alonso Martins
// 02/06/2024
#include <stdio.h>
#include <math.h>

int main()
{
    char c;
    int assuntos = 0;

    while (scanf("%c", &c) != EOF && c != '\n')
        assuntos += (1 - 2 * (c - '(')), assuntos = (int)fmax(assuntos, 0);

    printf(assuntos ? "Ainda temos %d assunto(s) pendente(s)!\n" : "Partiu RU!\n", assuntos);

    return 0;
}
