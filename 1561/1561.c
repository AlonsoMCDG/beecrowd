// bee 1561 - Relogio Binario
// Alonso Martins
// 07/07/2024
#include <stdio.h>

int main()
{
    int H, M, i, b;
    char h[4], m[6];

    while (scanf("%d%*c%d", &H, &M) != EOF)
    {
        for (i = 0, b = 8; i < 4; i ++, b /= 2)
            h[i] = (H >= b) ? 'o' : ' ', H %= b;
        
        for (i = 0, b = 32; i < 6; i ++, b /= 2)
            m[i] = (M >= b) ? 'o' : ' ', M %= b;
        
        printf(" ____________________________________________\n");
        printf("|                                            |\n");
        printf("|    ____________________________________    |_\n");
        printf("|   |                                    |   |_)\n");
        printf("|   |   8         4         2         1  |   |\n");
        printf("|   |                                    |   |\n");
        printf("|   |   %c         %c         %c         %c  |   |\n", h[0], h[1], h[2], h[3]);
        printf("|   |                                    |   |\n");
        printf("|   |                                    |   |\n");
        printf("|   |   %c     %c     %c     %c     %c     %c  |   |\n", m[0], m[1], m[2], m[3], m[4], m[5]);
        printf("|   |                                    |   |\n");
        printf("|   |   32    16    8     4     2     1  |   |_\n");
        printf("|   |____________________________________|   |_)\n");
        printf("|                                            |\n");
        printf("|____________________________________________|\n");
        printf("\n");
    }

    return 0;
}
