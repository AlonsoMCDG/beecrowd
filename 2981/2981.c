// bee 2981 - Vamos Fechar
// Alonso Martins
// 09/06/2024
#include <stdio.h>

int main()
{
    int dias_dos_meses[] = {30, 31};
    char *nomes_meses[] = {"setembro", "outubro"};
    unsigned C, G, dia, mes;

    scanf("%u %u", &C, &G);

    dia = 21 + C / G, mes = 0;
    
    while (dia > dias_dos_meses[mes])
        dia -= dias_dos_meses[mes ++];
    
    printf("A UFSC fecha dia %u de %s.\n", dia, nomes_meses[mes]);

    return 0;
}
