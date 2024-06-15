// bee 1257 - Array Hash
// Alonso Martins
// 14/06/2024
#include <stdio.h>

int hash_function(char *s, int pos)
{
    int i, hash = 0;

    for (i = 0; s[i] != '\0'; i ++)
        hash += s[i] - 'A' + pos + i;

    return hash;
}

int main()
{
    int N, L, i, hash;
    char string[52];

    scanf("%d", &N);
    
    while (N -- && scanf("%d", &L))
    {
        for (hash = i = 0; i < L; i ++)
        {
            scanf(" %s", string);
            hash += hash_function(string, i);
        }

        printf("%d\n", hash);
    }
    
    return 0;
}
