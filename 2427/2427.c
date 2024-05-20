// bee 2427 - Chocolate
// Alonso Martins
// 19/05/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, exp;
    long long resultado;

    scanf("%d", &N);
    
    exp = log2(N);
    resultado = pow(4, exp);

    printf("%lld\n", resultado);

    return 0;
}
