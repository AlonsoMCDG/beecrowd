// bee 1836 - Pokemon!
// Alonso Martins
// 22/07/2024
#include <stdio.h>
#include <math.h>

void calcular_atributo(char *atributo, int L)
{
    int Bs, IV, EV, S;
    int p = (atributo[0] == 'H' ? 50 : 0);

    scanf("%d %d %d", &Bs, &IV, &EV);

    S = ((IV + Bs + sqrt(EV) / 8 + p) * L) / 50 + 5 + p / 10;

    printf("%s: %d\n", atributo, S);
}

int main()
{
    int T, t = 0, L;
    char nome[200];

    scanf("%d", &T);

    while (T -- && ++ t)
    {
        scanf(" %s %d", nome, &L);

        printf("Caso #%d: %s nivel %d\n", t, nome, L);
        calcular_atributo("HP", L);
        calcular_atributo("AT", L);
        calcular_atributo("DF", L);
        calcular_atributo("SP", L);
    }

    return 0;
}
