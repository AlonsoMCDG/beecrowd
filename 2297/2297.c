// bee 2297 - Bafo
// Alonso Martins
// 01/06/2024
#include <stdio.h>

int main()
{
    int N, t = 0, pAldo, pBeto, q1, q2;

    while (pAldo = pBeto = 0, t ++, scanf("%d", &N), N)
    {
        while (N -- && scanf("%d %d", &q1, &q2))
            pAldo += q1, pBeto += q2;
        
        printf("Teste %d\n", t);
        printf("%s\n\n", pAldo > pBeto ? "Aldo" : "Beto");
    }

    return 0;
}
