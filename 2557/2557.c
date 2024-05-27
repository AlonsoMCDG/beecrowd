// bee 2557 - R+L=J
// Alonso Martins
// 26/05/2024
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ans, i, sz, flag, cont;
    char A[10], B[10], C[10], string[20];
    char var, c;

    while (scanf("%s", string) != EOF)
    {
        for (sz = strlen(string), cont = flag = i = 0; i < sz; i ++)
        {
            c = string[i];
            if (c == 'R' || c == 'L' || c == 'J')
                var = c;
            else if (c == '+' || c == '=')
            {
                flag++, cont = 0;
                continue;
            }
            
            if (flag == 0)
                A[cont ++] = c, A[cont] = '\0';
            else if (flag == 1)
                B[cont ++] = c, B[cont] = '\0';
            else
                C[cont ++] = c, C[cont] = '\0';
        }

        switch (var)
        {
            case 'R': ans = atoi(C) - atoi(B); break;
            case 'L': ans = atoi(C) - atoi(A); break;
            case 'J': ans = atoi(A) + atoi(B); break;
            default: break;
        }

        printf("%d\n", ans);
    }

    return 0;
}
