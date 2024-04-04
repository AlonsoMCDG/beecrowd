// bee 1103 - Alarme Despertador
// Alonso Martins
// 03/04/2024
#include <stdio.h>

int main()
{
    int H1, M1, H2, M2, tempo;

    while (scanf("%d %d %d %d", &H1, &M1, &H2, &M2) && (H1 + M1 + H2 + M2))
    {
        tempo = (H2 * 60 + M2) - (H1 * 60 + M1);
        tempo += 24 * 60 * (tempo < 0);
        printf("%d\n", tempo);
    }
    return 0;
}
