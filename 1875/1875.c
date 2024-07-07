// bee 1875 - Tribol
// Alonso Martins
// 06/07/2024
#include <stdio.h>

#define ctoi(x) ((x - 'A' + 1) % 3)

int max(int x, int y, int z) { return x > y && x > z ? x : y > z ? y : z; }
int min(int x, int y, int z) { return x < y && x < z ? x : y < z ? y : z; }

char * calcular_resultado(int *p)
{
    int r = p[0], g = p[1], b = p[2], x, y;

    return r > g && r > b ? "red" 
         : g > r && g > b ? "green"
         : b > r && b > g ? "blue"
       : r == g && g == b ? "trempate"
                          : "empate";
}
int main()
{
    int C, N, i, j;

    scanf("%d", &C);

    while (C -- && scanf("%d", &N))
    {
        int pontos[3] = {}; // [R][G][B]
        int aEsquerda[3] = {1, 2, 0};
        char M, S;

        while (N -- && scanf(" %c %c", &M, &S))
            pontos[ctoi(M)] += 1 + (ctoi(S) == aEsquerda[ctoi(M)]);
        
        printf("%s\n", calcular_resultado(pontos));
    }

    return 0;
}
