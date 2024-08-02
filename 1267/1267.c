// bee 1267 - Biblioteca Pascal
// Alonso Martins
// 02/08/2024
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N, D, i, j, presenca;

    while (scanf("%d %d", &N, &D), N && D)
    {
        int presencas[100] = {};
        bool ans = false;

        for (i = 0; i < D; i ++)
        {
            for (j = 0; j < N; j ++)
            {
                scanf("%d", &presenca);
                presencas[j] += presenca;

                if (!ans && presencas[j] == D)
                    ans = true;
            }
        }

        printf("%s\n", ans ? "yes" : "no");
    }

    return 0;
}
