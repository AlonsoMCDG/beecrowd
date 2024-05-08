// bee 1138 - Contagem de Digitos
// Alonso Martins
// 07/05/2024
#include <stdio.h>
#include <math.h>

void imprimir_vetor(char *label, int n, int v[10]) // para debug
{
    int i;
    printf("%s%d\n", label, n);
    for (i = 0; i < 10; i ++)
        printf("%d%s", v[i], i == 9 ? "\n" : ", ");
}

void contar_digitos(int v[10], int _n)
{
    if (_n == 0) 
        return;

    int t1, t2, t3, dig;
    int i, n = _n, aux, aux1, d, contador;

    // unidades
    for (i = 1; i < 10; i ++)
        v[i] += n / 10 + (n % 10 >= i);

    v[0] = n / 10; // o zero conta diferente

    // resto das casas
    for (i = 1; i <= 8; i ++)
    {
        t1 = (int)pow(10, i);
        t2 = n / (int)pow(10, i + 1);
        t3 = n % t1 + 1;
        dig = (n / t1) % 10;

        v[0] += (t2 > 1) * (t2 - 1) * t1 + (t2 && dig) * t1 + (t2 && !dig) * t3; // o zero conta diferente

        for (d = 1; d < 10; d ++)   // conta os dígitos de 1 a 9 na posicao 10^i
        {
            contador = (t2 + (dig > d)) * t1 + t3 * (dig == d);
            v[d] += contador;
        }

        if (t2 == 0)
            break;
    }
}

int main()
{
    int A, B, i;

    while (scanf("%d %d", &A, &B) && A + B)
    {
        int left_bound[10] = {}, right_bound[10] = {};
        
        contar_digitos(left_bound, A - 1);
        contar_digitos(right_bound, B);

        for (i = 0; i < 10; i ++)
            printf("%d%s", right_bound[i] - left_bound[i], i == 9 ? "\n" : " ");
    }

    return 0;
}
