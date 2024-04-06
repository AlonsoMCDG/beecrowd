// bee 3249 - Death Knight Hero
// Alonso Martins
// 05/04/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, vitorias = 0;
    char k[1001];
    scanf("%d", &N);
    
    while (N--)
    {
        scanf("%s", k);
        if (strstr(k, "CD") == NULL)
            vitorias ++;
    }
    
    printf("%d\n", vitorias);
    
    return 0;
}
