// bee 1873 - Pedra-papel-tesoura-lagarto-Spock
// Alonso Martins
// 07/06/2024
#include <stdio.h>
#define GETNUM(x) (((x[0] + x[1]) % 205) / 4)
// lagarto - 0
//   papel - 1
//   pedra - 2
// tesoura - 3
//   spock - 5

int max(int a, int b) { return a > b ? a : b; }

int main()
{
    int N;
    int n1, n2, p1, p2;
    char s1[20], s2[20];
    char *resultado[3] = { "empate", "rajesh", "sheldon" };
    int jogos[6][6] = {
        { 0,  1, -1, -1, 0,  1},
        {-1,  0,  1, -1, 0,  1},
        { 1, -1,  0,  1, 0, -1},
        { 1,  1, -1,  0, 0, -1},
        { 0,  0,  0,  0, 0,  0},
        {-1, -1,  1,  1, 0,  0}
    };
    scanf("%d", &N);

    while (N-- && scanf(" %s %s", s1, s2))
    {
        n1 = GETNUM(s1), n2 = GETNUM(s2);
        p1 = 1 * jogos[n1][n2], p2 = 2 * jogos[n2][n1];
        printf("%s\n", resultado[max(p1, p2)]);
    }
    
    return 0;
}
