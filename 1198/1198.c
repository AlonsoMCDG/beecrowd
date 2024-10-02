// bee 1198 - O Bravo Guerreiro Hashmat
// Alonso Martins
// 01/10/2024
#include <stdio.h>

#define abs(x) (x < 0 ? -(x) : (x))

int main()
{
    long long A, B;

    while (scanf("%lld %lld", &A, &B) != EOF)
        printf("%lld\n", abs(A - B));

    return 0;
}
