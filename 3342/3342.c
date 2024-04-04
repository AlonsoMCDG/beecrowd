// bee 3342 - Keanu
// Alonso Martins
// 20/02/2024
#include <stdio.h>

int main()
{
    int n, brancas = 0, pretas = 0;

    scanf("%d", &n);
    
    pretas = (n * n - (n % 2)) / 2;
    brancas = pretas + (n % 2);
    
    printf("%d casas brancas e %d casas pretas\n", brancas, pretas);
    
    return 0;
}
