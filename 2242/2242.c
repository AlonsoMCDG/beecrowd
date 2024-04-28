// bee 2242 - Huaauhahhuahau
// Alonso Martins
// 28/04/2024
#include <stdio.h>
#include <string.h>

int eh_vogal(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    char risada[52];
    char esq[52], dir[52];
    int i, size, ce, cd = ce = 0;

    scanf("%s", risada);
    size = strlen(risada);

    for (i = 0; i < size; i ++)
    {
        if (eh_vogal(risada[i]))
            esq[ce ++] = risada[i];
        if (eh_vogal(risada[size - i - 1]))
            dir[cd ++] = risada[size - i - 1];
    }
    
    esq[ce] = dir[cd] = '\0';

    printf(strcmp(esq, dir) ? "N\n" : "S\n");

    return 0;
}
