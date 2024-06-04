// bee 1300 - Horas e Minutos
// Alonso Martins
// 03/06/2024
#include <stdio.h>

int main()
{
    int A;

    while (scanf("%d", &A) != EOF)
        printf("%s\n", A % 6 ? "N" : "Y");

    return 0;
}
