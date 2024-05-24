// bee 1870 - Ventiladores e Baloes
// Alonso Martins
// 24/05/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int L, C, P;
    
    while (scanf("%d %d %d", &L, &C, &P), L + C + P)
    {
        int i, j, m[L][C], esquerda, ie, direita, id, estourou = 0;

        for (i = 0; i < L; i ++)
            for (j = 0; j < C; j ++)
                scanf("%d", &m[i][j]);

        if (estourou = P > C, estourou)
        {
            printf("BOOM %d %d\n", 1, P);
            continue;
        }
        
        for (P -= 1, i = 0; i < L; i ++)
        {
            if (estourou = m[i][P], estourou)
            {
                printf("BOOM %d %d\n", i + 1, P + 1);
                break;
            }

            esquerda = direita = 0;

            for (j = 1; !esquerda || !direita; j ++)
            {
                int aux;
                if (aux = P - j, !esquerda && aux >= 0 && m[i][aux])
                    esquerda = m[i][aux], ie = aux;

                if (aux = P + j, !direita && aux < C && m[i][aux])
                    direita = m[i][aux], id = aux;
            }

            P += esquerda - direita;

            if (estourou = (P <= ie || P >= id), estourou)
            {
                printf("BOOM %d %d\n", i + 1, P + 1);
                break;
            }
        }

        if (!estourou)
            printf("OUT %d\n", P + 1);
    }

    return 0;
}
