// bee 1619 - Diferenca entre Datas
// Alonso Martins
// 28/09/2024
#include <stdio.h>
#include <stdlib.h>

int dias_dos_meses[] = {      31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int soma_dias_nbis[] = {0, 0, 31, 59, 90,120,151,181,212,243,273,304,334,365};

int anos_bissextos_ate(int ano)
{
    return ano / 4 - ano / 100 + ano / 400;
}

int eh_bissexto(int ano)
{
    return !(ano % 400) || !(ano % 4) && (ano % 100); 
}

int para_dias(int ano, int mes, int dia)
{
    int dias;

    dias = ano * 365 + anos_bissextos_ate(ano - 1);
    dias += soma_dias_nbis[mes] + (eh_bissexto(ano) && (mes > 2));
    dias += dia;

    return dias;
}

int main()
{
    int N, i;
    int data1, ano1, mes1, dia1;
    int data2, ano2, mes2, dia2;
    int inicio, fim;

    scanf("%d", &N);

    while (N -- && scanf("%d-%d-%d %d-%d-%d", &ano1, &mes1, &dia1, &ano2, &mes2, &dia2))
    {
        fim = para_dias(ano1, mes1, dia1);
        inicio = para_dias(ano2, mes2, dia2);

        printf("%d\n", abs(fim - inicio));
    }

    return 0;
}
