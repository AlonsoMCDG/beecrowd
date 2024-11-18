// bee 1068 - Balanco de Parenteses I
// Alonso Martins
// 18/11/2024
#include <stdio.h>

int main()
{
    char exp[1002];

    while (scanf(" %[^\n]", &exp) != EOF)
    {
        int stack = 0, i;

        for (i = 0; exp[i] && stack >= 0; i ++)
            stack += (exp[i] == '(' ? 1 : (exp[i] == ')' ? -1 : 0));

        printf("%scorrect\n", stack ? "in" : "");
    }

    return 0;
}
