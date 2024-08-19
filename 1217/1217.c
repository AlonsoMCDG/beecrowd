// bee 1217 - Getline Two - Frutas
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int dias, dia_atual = 0;
    int totalQuilos = 0, quilos;
    double totalGasto = 0, preco;
    char listaDeFrutas[10000];

    scanf("%d", &dias);

    for (dia_atual = 1; dia_atual <= dias; dia_atual ++)
    {
        scanf("%lf %[^\n]", &preco, listaDeFrutas);
        char *fruta = strtok(listaDeFrutas, " ");
        quilos = 0;

        while (fruta)
        {
            quilos ++;
            fruta = strtok(NULL, " ");
        }

        totalGasto += preco;
        totalQuilos += quilos;

        printf("day %d: %d kg\n", dia_atual, quilos);
    }

    printf("%.2lf kg by day\n", (double) totalQuilos / dias);
    printf("R$ %.2lf by day\n", (double) totalGasto / dias);

    return 0;
}
