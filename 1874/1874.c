// bee 1874 - Empurrando Blocos
// Alonso Martins
// 26/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int H, P, F, i, j;

    while (scanf("%d %d %d", &H, &P, &F) && H + P + F)
    {
        int pilhas[H][P], topoPilha[P], fila[F];
        int indexFila, coluna;

        memset(topoPilha, 0, P * sizeof(int));

        for (i = 0; i < H; i ++)
            for (j = 0; j < P; j ++)
            {
                scanf("%d", &pilhas[i][j]);

                if (!pilhas[i][j])
                    topoPilha[j] = i + 1;
            }

        for (i = 0; i < F; i ++)
            scanf("%d", &fila[i]);

        for (indexFila = 0, coluna = P - 1; coluna >= 0 && indexFila != F; coluna --)
            while (topoPilha[coluna] != 0 && indexFila != F)
                pilhas[-- topoPilha[coluna]][coluna] = fila[indexFila ++];

        for (i = 0; i < H; i ++)
            for (j = 0; j < P; j ++)
                printf("%d%s", pilhas[i][j], j == P - 1 ? "\n" : " ");
    }

    return 0;
}
