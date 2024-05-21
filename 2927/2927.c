// bee 2927 - Imprevistos Natalinos
// Alonso Martins
// 21/05/2024
#include <stdio.h>

int main()
{
    int A, C, X, Y;

    scanf("%d %d %d %d", &A, &C, &X, &Y);

    if (A > C - (X + Y) - 1)
    {
        if (X > Y / 2)
            printf("Caio, a culpa eh sua!\n");
        else
            printf("Igor bolado!\n");
    }
    else
        printf("Igor feliz!\n");

    return 0;
}
