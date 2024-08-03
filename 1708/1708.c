// bee 1708 - Volta
// Alonso Martins
// 21/07/2024
#include <stdio.h>
#include <math.h>

int main()
{
    double X, Y;

    scanf("%lf %lf", &X, &Y);

    printf("%d\n", (int)ceil(1 / (1 - X / Y)));

    return 0;
}

/*
....A....A....A....A....A
......B......B......B

tempo = t
voltas_A = a
voltas_B = b
tempo_de_uma_volta_de_A = X
tempo_de_uma_volta_de_B = Y

Quando A ultrapassa B no tempo t, temos que: 
a == b + 1 <=> a - 1 == b

Entao
a * X <= b * Y
a * X <= (a - 1) * Y
X / Y <= (a - 1) / a
X / Y <= 1 - 1 / a
X / Y - 1 <= - 1 / a
1 / a <= 1 - X / Y
1 / (1 - X / Y) <= a
a >= 1 / (1 - X / Y)

*/
