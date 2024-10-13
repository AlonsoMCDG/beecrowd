// bee 3454 - Alice no Pais do Jogo da Velha
// Alonso Martins
// 13/10/2024
#include <stdio.h>

char * resultado(char a, char b, char c)
{
    if (b == 'X')  // {-X-}
    {
        if (a != c) return "Alice"; // {OXX, XXO}
        return "?"; // {OXO, XXX}
    }

    // {-O-}
    if (a == c && a == 'X') // {XOX}
        return "*";

    return "?"; // {XOO, OOX, OOO}
}

int main()
{
    char a, b, c;

    scanf("%c%c%c", &a, &b, &c);

    printf("%s\n", resultado(a, b, c));

    return 0;
}
