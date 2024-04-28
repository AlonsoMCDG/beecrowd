// bee 1581 - Conversa Internacional
// Alonso Martins
// 28/04/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i;
    char s1[21], s2[21];

    scanf("%d", &N);

    while (N --)
    {
        char *ans = NULL;

        scanf("%d%*c%s", &K, s1);

        for (i = 1; i < K; i ++)
        {
            scanf("%s", s2);

            if (strcmp(s1, s2))
                ans = "ingles";

            strcmp(s1, s2);
        }

        printf("%s\n", ans ? ans : s2);
    }
    
    return 0;
}
