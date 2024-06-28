// bee 2814 - Musica Alta
// Alonso Martins
// 28/06/2024
#include <stdio.h>
#include <math.h>

typedef struct Ponto
{
    int x;
    int y;
} Ponto;

int dist(Ponto p1, Ponto p2)
{
    return (int)(10 * sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

int main()
{
    int N, K, S, i, j;
    char c;
    Ponto F, J;

    scanf("%d", &N);

    while (N -- && scanf("%d %d", &K, &S))
    {
        i = 0, j = 0, c = getchar();
        while (i < S && c != EOF)
        {
            c = getchar();

            if (c == 'F')
                F.x = j, F.y = i;
            else if (c == 'J')
                J.x = j, J.y = i;

            j ++;

            if (c == '\n')
                i ++, j = 0;
        }

        printf("%d dBs\n", (int)floor((double)K / pow(0.99, dist(F, J))));
    }

    return 0;
}
