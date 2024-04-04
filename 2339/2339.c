// bee 2339 - Avioes de Papel
// Alonso Martins
// 13/03/2024
#include <stdio.h>

int main()
{
    int C, P, F;
    
    scanf("%d %d %d", &C, &P, &F);
    printf(C * F <= P ? "S\n" : "N\n");
    return 0;
}
