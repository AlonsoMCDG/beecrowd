// bee 1953 - Roberto e a Sala Desenfreada
// Alonso Martins
// 28/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, epr, ehd, intrusos;
    char matr[8], turma[50];

    while (epr = ehd = intrusos = 0, scanf("%d", &N) != EOF)
    {
        while (N -- && scanf(" %s %s", matr, turma))
            if (!strcmp(turma, "EPR")) epr ++;
            else if (!strcmp(turma, "EHD")) ehd ++;
            else intrusos ++;

        printf("EPR: %d\nEHD: %d\nINTRUSOS: %d\n", epr, ehd, intrusos);
    }

    return 0;
}
