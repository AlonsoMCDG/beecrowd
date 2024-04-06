// bee 3301 - Sobrinho do Meio
// Alonso Martins
// 05/04/2024
#include <stdio.h>
#include <stdlib.h>
int comparar(const void *a, const void *b)
{
    const char (*A)[2][15] = (const char (*)[2][15])a;
    const char (*B)[2][15] = (const char (*)[2][15])b;
    return atoi((*A)[1]) - atoi((*B)[1]);
}
int main()
{
    int i, j;
    char irmaos[][2][15] = {{"huguinho", ""}, {"zezinho", ""}, {"luisinho", ""}};
    
    for (i = 0; i < 3; i ++)
        scanf("%s", irmaos[i][1]);
    
    qsort(irmaos, 3, sizeof(char [2][15]), comparar);
    
    printf("%s\n", irmaos[1][0]);
    
    return 0;
}
