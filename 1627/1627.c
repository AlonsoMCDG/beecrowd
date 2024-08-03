// bee 1627 - Ultimo Dano
// Alonso Martins
// 02/08/2024
#include <stdio.h>

enum 
{
    ANDRE,
    BETO
};

int get_vez(int *cd)
{
    return cd[BETO] < cd[ANDRE] ? BETO : ANDRE;
}

int main()
{
    int T, HP, atk[2], tempo[2], cooldown[2];
    char *ans[2] = {"Andre", "Beto"};
    scanf("%d", &T);

    while (T -- && scanf("%d %d %d %d %d", &atk[ANDRE], &cooldown[ANDRE], &atk[BETO], &cooldown[BETO], &HP))
    {
        int vez = ANDRE;
        tempo[ANDRE] = cooldown[ANDRE];
        tempo[BETO] = cooldown[BETO];

        HP -= atk[ANDRE];
        if (HP > 0) vez = BETO;
        HP -= atk[BETO];

        while (HP > 0)
        {
            vez = get_vez(tempo);
            HP -= atk[vez];
            tempo[vez] += cooldown[vez];
        }

        printf("%s\n", ans[vez]);
    }

    return 0;
}
