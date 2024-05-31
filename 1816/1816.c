// bee 1816 - Vikings em Praga?
// Alonso Martins
// 31/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int M, K, i, instancia;

    for (instancia = 1; scanf("%d", &M), M && printf("Instancia %d\n", instancia); instancia ++, printf("\n\n"))
    {
        char lista[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", c;
        
        while (M -- && scanf("%d", &K))
        {
            c = lista[-- K];
            for (i = K; i > 0; i --)
                lista[i] = lista[i - 1];
            lista[0] = c;

            printf("%c", c);
        }
    }

    return 0;
}
