// bee 1680 - Borda
// Alonso Martins
// 24/09/2024
#include <stdio.h>
#include <string.h>

enum
{
    NORTE = 0,
    LESTE = 1,
    SUL = 2,
    OESTE = 3
};

int main()
{
    char str[210];
    int i, sz;
    int pos[4][2] = {{0, 10}, {10, 0}, {0, -10}, {-10, 0}};

    while (scanf(" %s", str) != EOF)
    {
        int x = 310, y = 420;
        int heading = LESTE;
        sz = strlen(str);

        printf("300 420 moveto\n");
        printf("310 420 lineto\n");
        for (i = 0; i < sz; i ++)
        {
            if (str[i] == 'V')
                heading = (4 + heading - 1) % 4;
            else
                heading = (heading + 1) % 4;

            x += pos[heading][0];
            y += pos[heading][1];

            printf("%d %d lineto\n", x, y);
        }
        printf("stroke\nshowpage\n");
    }

    return 0;
}
