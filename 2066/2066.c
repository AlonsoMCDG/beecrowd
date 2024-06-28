// bee 2066 - amelborP mU
// Alonso Martins
// 25/06/2024

/*** Definições:
 * -> K(n) é a quantidade de números de N algarismos, onde o PRIMEIRO é MAIOR que o ÚLTIMO, que são MAIORES que o seu REVERSO
 *   --> ex.: para n = 5, n é do tipo: ABCDE, onde ABCDE > EDCBA e A > E
 * -> L(n) é a quantidade de números de N algarismos, onde o PRIMEIRO é IGUAL ao ÚLTIMO, que são MAIORES que seu REVERSO
 *   --> ex.: para n = 5, n é do tipo: ABCDE, onde ABCDE > EDCBA e A == E, ou ainda, n = ABCDA > ADCBA
 * -> J(n) é a quantidade de números de N algarismos que são IGUAIS ao seu REVERSO
 *   --> ex.: para n = 5, n é do tipo: ABCDE, onde ABCDE == EDCBA, ou ainda, n = ABCBA
 * -> F(n) é a quantidade de números de N algarismos que são MENORES que seu REVERSO
 *   --> ex.: para n = 5, n é do tipo: ABCDE, onde ABCDE < EDCBA
 * 
 * 
 *** Fórmulas gerais:
 * > K(n) = 0, n < 2 | 45 * 10^(n - 2), n >= 2
 * > L(n) = 0, n < 2 | 9 * [K(n - 2) + L(n - 2)], n >= 2
 * > J(n) = 9 * 10^[int((n - 1) / 2)], n > 0
 * > F(n) = 9 * 10^(n - 1) - K(n) - J(n) - L(n), n > 0
 */
 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

ll pot(int n)
{ // retorna 10^n, n >= 0
    char s[] = "10000000000000000000";
    s[n + 1] = '\0';
    return strtoll(s, NULL, 10);
}

ll K(int n)
{
    return n < 2 ? 0 : (45 * pot(n - 2));
}

ll L(int n)
{
    return n < 2 ? 0 : 9 * (K(n - 2) + 10 * L(n - 2) / 9);
}

ll J(int n)
{
    return n > 0 ? 9 * pot((n - 1) / 2) : 0;
}

ll F(int n)
{
    return n > 0 ? 9 * pot(n - 1) - K(n) - J(n) - L(n) : 0;
}

int main()
{
    int K;

    scanf("%d", &K);

    printf("%lld\n", F(K));

    return 0;
}
