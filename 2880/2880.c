// bee 2880 - Enigma
// Alonso Martins
// 28/04/2024
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10002
int main()
{
    char cifra[MAX_LENGTH];
    char crib[MAX_LENGTH];
    int i, j, size;
    int ans = 0;

    scanf("%s %s", cifra, crib);

    size = strlen(crib);
    
    for (i = 0; i < strlen(cifra) - size + 1; i ++)
    {
        if (cifra[i] != crib[0])
        {
            for (j = 1; j < size; j ++)
                if (cifra[i + j] == crib[j])
                    break;
            ans += (j == size);
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
