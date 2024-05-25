// bee 1366 - Jogo das Varetas
// Alonso Martins
// 25/05/2024
#include <stdio.h>

typedef struct
{
    int tamanho, quantidade;
} Vareta;

int main()
{
    int N, i;
    
    while (scanf("%d", &N), N)
    {
        int retangulos = 0;
        int cont;
        Vareta varetas[N];

        for (cont = i = 0; i < N; i ++)
        {
            scanf("%d %d", &varetas[i].tamanho, &varetas[i].quantidade);
            retangulos += varetas[i].quantidade / 4;
            varetas[i].quantidade %= 4;
            cont += varetas[i].quantidade / 2;
            if (cont == 2)
                cont = 0, retangulos ++;
        }

        printf("%d\n", retangulos);
    }

    return 0;
}
