// bee 2138 - Digito Mais Frequente
// Alonso Martins
// 07/09/2024
#include <stdio.h>

int maior_frequencia(char *s)
{
    int n, frequencia[10] = {}, m, f = -1, i;

    while ((n = *s ++))
        frequencia[n - '0'] ++;
    
    for (i = 0; i < 10; i ++)
        if (frequencia[i] >= f)
            f = frequencia[i], m = i;

    return m;
}

int main()
{
    char num[1003];

    while (scanf(" %s", num) != EOF)
        printf("%d\n", maior_frequencia(num));

    return 0;
}
