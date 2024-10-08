// bee 2233 - Etiquetas Coloridas
// Alonso Martins
// 08/10/2024
#include <stdio.h>

typedef long long ll;

int main()
{
    int R, G, B;

    scanf("%x %x %x", &R, &G, &B);

    ll lado_G = R / G;
    ll lado_B = G / B;
    ll total_G = lado_G * lado_G;
    ll total_B = lado_B * lado_B * total_G;
    ll total = 1 + total_G + total_B;

    int AH = total >> 32;       // parte alta
    int AL = total << 32 >> 32; // parte baixa

    if (AH) printf("%x%08x\n", AH, AL);
    else printf("%x\n", AL);

    return 0;
}
