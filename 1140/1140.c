// bee 1140 - Flores Florescem da Franca
// Alonso Martins
// 23/08/2024
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char sentenca[50*20+51], *palavra, inicial, ans;

    while (scanf(" %[^\n]", sentenca), sentenca[0] != '*')
    {
        palavra = strtok(sentenca, " ");
        ans = 'Y';
        inicial = tolower(palavra[0]);

        while (palavra)
        {
            if (tolower(palavra[0]) != inicial)
            {
                ans = 'N';
                break;
            }
            palavra = strtok(NULL, " ");
        }

        printf("%c\n", ans);
    }

    return 0;
}
