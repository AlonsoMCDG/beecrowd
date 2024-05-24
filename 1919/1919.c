// bee 1919 - Ajude Nhonho
// Alonso Martins
// 23/05/2024
#include <stdio.h>

int soma(int *v)
{
    return v[0] + v[1] + v[2] + v[3] + v[4];
}

int printConjunto(int *v)
{
    printf("{%d,%d,%d,%d,%d}\n", v[0], v[1], v[2], v[3], v[4]);
}

int main()
{
    int T, K, *e, p;

    scanf("%d", &T);

    while (p = 0, T -- && scanf("%d", &K))
    {
        int elementos[] = {0, 1, 2, 3, 4};
        
        for (elementos[0] = 0; elementos[0] <= 5; elementos[0] ++)
            for (elementos[1] = elementos[0] + 1; elementos[1] <= 6; elementos[1] ++)
                for (elementos[2] = elementos[1] + 1; elementos[2] <= 7; elementos[2] ++)
                    for (elementos[3] = elementos[2] + 1; elementos[3] <= 8; elementos[3] ++)
                        for (elementos[4] = elementos[3] + 1; elementos[4] <= 9; elementos[4] ++)
                            if (soma(elementos) * 266664 == K)
                                printConjunto(elementos), p ++;
                                
        if (p == 0) printf("impossivel\n");
        printf("\n");
    }

    return 0;
}
