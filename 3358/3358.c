// bee 3358 - Sobrenome Nao e Facil
// Alonso Martins
// 28/04/2024
#include <stdio.h>
#include <ctype.h>

int eh_vogal(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void checar(char *s)
{
    int i, cont = 0;
    for (i = 0; i < strlen(s); i ++)
    {
        if (!eh_vogal(s[i]))
            cont++;
        else
            cont = 0;
        if (cont == 3)
        {
            printf("%s nao eh facil\n", s);
            return;
        }
    }
    printf("%s eh facil\n", s);
}

int main()
{
    char sobrenome[44];
    int N;

    scanf("%d%*c", &N);
    
    while (N --)
    {
        scanf("%s", sobrenome);

        checar(sobrenome);
    }

    return 0;
}
