// bee 2062 - OBI URI
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    char str[22];

    scanf("%d", &N);

    while (N -- && scanf(" %s", &str))
    {
        if (strlen(str) == 3 && (!strncmp(str, "OB", 2) || !strncmp(str, "UR", 2)))
            str[2] = 'I';

        printf("%s%s", str, N ? " " : "\n");
    }

    return 0;
}
