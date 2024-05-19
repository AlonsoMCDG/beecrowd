// bee 2953 - Mais um Joguinho
// Alonso Martins
// 18/05/2024
#include <stdio.h>

#define r 1000000007
typedef unsigned long long ull;

void lshift(ull *v)
{
    int i;
    for (i = 0; i < 3; i ++)
        v[i] = v[i + 1];
}

int main()
{
    int N, i; scanf("%d", &N);
    ull P[4] = {1, 0, 0, 0}; 

    for (i = 0; i < N; i ++)
    {
        P[3] = (P[0] + P[1]) % r;
        lshift(P);
    }

    printf("%llu\n", P[3]);

    return 0;
}
