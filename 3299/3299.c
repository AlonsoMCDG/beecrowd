// 3299 - Numeros Ma Sorte Pequenos
// Alonso Martins
// 08/10/2024
#include <stdio.h>

int main()
{
    char N[20];
    int i, ans = 0;

    scanf("%s", N);

    for (i = 1; N[i]; i ++)
        if (N[i - 1] == '1' && N[i] == '3')
        {
            ans = 1;
            break;
        }
    
    printf("%s %ses de Mala Suerte\n", N, ans ? "" : "NO ");

    return 0;
}
