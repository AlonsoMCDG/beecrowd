// bee 1216 - Getline One
// Alonso Martins
// 18/08/2024
#include <stdio.h>

int main()
{
    char nome[1000];
    int amigos = 0, dist;
    double media = 0;

    while (fgets(nome, 1000, stdin))
    {
        scanf("%d", &dist);
        media += dist;
        amigos ++;        
    }

    printf("%.1lf\n", media / amigos);

    return 0;
}
