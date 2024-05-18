// bee 2868 - Errrou!
// Alonso Martins
// 18/05/2024
#include <stdio.h>
#include <math.h>

void imprimirSaida(int N)
{
    printf("E");
    while (N --) printf("r");
    printf("ou!\n");
}

int main()
{
    int N, A, B, R, res;
    char op;

    scanf("%d", &N);

    while (N -- && scanf("%d %c %d %*c %d", &A, &op, &B, &R))
    {
        if (op == '+') res = A + B;
        else if (op == '-') res = A - B;
        else res = A * B;

        imprimirSaida(abs(abs(res) - abs(R)));
    }

    return 0;
}
