// bee 1240 - Encaixa ou Nao I
// Alonso Martins
// 01/10/2024
#include <stdio.h>

int resto(int a, int b)
{
    int p = 1;
    while (a)
    {
        p *= 10;
        a /= 10;
    }
    
    return b % p;
}

int main()
{
    int A, B;
    scanf("%d", &A);
    
    while (scanf("%d %d", &A, &B) != EOF)
    {
        A = resto(B, A);
        
        printf("%sencaixa\n", A == B ? "" : "nao ");
    }
    
    return 0;
}
