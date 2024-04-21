// bee 2830 - Copa
// Alonso Martins
// 20/04/2024
#include <stdio.h>

int main()
{
    int K, L, fase = 8;
    char *ans;

    scanf("%d %d", &K, &L);
    
    while (1)
    {
        if (K + K % 2 == L + L % 2)
            break;
        K = K / 2 + K % 2;
        L = L / 2 + L % 2;
        fase /= 2;
    }

    switch (fase)
    {
        case 1: ans = "final"; break;
        case 2: ans = "semifinal"; break;
        case 4: ans = "quartas"; break;
        case 8: ans = "oitavas"; break;
        default: break;
    }

    printf("%s\n", ans);

    return 0;
}
