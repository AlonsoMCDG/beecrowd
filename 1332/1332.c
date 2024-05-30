// bee 1332 - Um-Dois-Tres
// Alonso Martins
// 30/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, i;
    char palavra[7];

    scanf("%d", &N);

    while (N --&& scanf(" %s", palavra))
    {
        if (strlen(palavra) == 5 && printf("3\n"))
            continue;

        char *s1 = "one", *s2 = "two";
        int one = 0, two = 0;

        for (i = 0; i < 3; i ++)
        {
            one += s1[i] == palavra[i];
            two += s2[i] == palavra[i];
        }

        printf("%d\n", one > two ? 1 : 2);
    }

    return 0;
}
