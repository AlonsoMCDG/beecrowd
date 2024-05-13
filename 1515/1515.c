// bee 1515 - Hello Galaxy
// Alonso Martins
// 13/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char nome[52], planeta[52] = "";
    int N, ano, tempo, maisAntiga;

    while (maisAntiga = 0, scanf("%d", &N) && N)
    {
        getchar(); // remove '\n'
        while (N --)
        {
            scanf("%s %d %d", nome, &ano, &tempo);
            if (maisAntiga == 0 || ano - tempo < maisAntiga)
            {
                maisAntiga = ano - tempo;
                strcpy(planeta, nome);
            }
        }

        printf("%s\n", planeta);
    }

    return 0;
}
