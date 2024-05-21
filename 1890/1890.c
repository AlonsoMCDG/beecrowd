// bee 1890 - Emplacando os Tuk-tuks
// Alonso Martins
// 21/05/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, C, D; scanf("%d", &N);

    while (N -- && scanf("%d %d", &C, &D))
        printf("%u\n", C + D ? (unsigned int)(pow(26, C) * pow(10, D)) : 0);

    return 0;
}
