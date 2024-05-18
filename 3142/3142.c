// bee 3142 - Excel Bugado
// Alonso Martins
// 18/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char scoluna[13];
    int icoluna, sz, i, ic;

    while (scanf("%s", scoluna) != EOF)
    {
        if (sz = strlen(scoluna), sz > 3)
            icoluna = 16385;
        else
            for (icoluna = 0, ic = 1, i = sz - 1; i >= 0; i --, ic *= 26)
                icoluna += (scoluna[i] - 'A' + 1) * ic;

        printf(icoluna <= 16384 ? "%d\n" : "Essa coluna nao existe Tobias!\n", icoluna);
    }

    return 0;
}
