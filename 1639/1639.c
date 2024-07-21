// bee 1639 - Gerando Numeros Aleatorios
// Alonso Martins
// 16/06/2024
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 10000
int precalcular = 0;

int ans[MAXN] = {};

int neumann_rand(int x)
{
    char new_x[9] = "00000000";
    int i;
    x *= x;

    for (i = 7; i >= 0; i --)
        new_x[i] = x % 10 + '0', x /= 10;

    new_x[6] = '\0';

    return atoi(&new_x[2]);
}

void calcular_numeros_aleatorios()
{
    int stack[MAXN], top = -1;
    int i, next, num;

    for (i = 0; i < MAXN; i ++)
    {
        bool is_on_stack[MAXN] = {};
        if (!is_on_stack[i])
        {
            int cont = 1;
            is_on_stack[i] = true;

            next = neumann_rand(i);
            while (!is_on_stack[next])
            {
                is_on_stack[next] = true;
                cont ++;
                next = neumann_rand(next);
            }

            ans[i] = cont;
        }
    }

    if (precalcular)
    {
        printf("int ans[MAXN] = {");
        for (i = 0; i < MAXN; i ++)
            printf("%s%d", i ? ", " : " ", ans[i]);
        printf(" };\n");
    }
}

int main()
{
    int N, i;

    calcular_numeros_aleatorios();

    if (!precalcular)
        while (scanf("%d", &N), N)
            printf("%d\n", ans[N]);

    return 0;
}
