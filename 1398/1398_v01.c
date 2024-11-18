// bee 1398 - Oceano Profundo! Faca-o Raso!!
// Alonso Martins
// 18/11/2024
#include <stdio.h>
#include <string.h>

int is_divisible_by(char *numerator, int denominator)
{
    int mod = 0, c;

    while ((c = *numerator ++))
        mod = ((mod << 1) | (c & 1)) % denominator;

    return mod == 0;
}

int main()
{
    int n = 0, den = 131071;
    char c, num[10502];

    while (scanf("%c", &c) != EOF)
    {
        if (c == '0' || c == '1')
            num[n ++] = c;

        if (c == '#')
        {
            num[n] = '\0';
            printf("%s\n", is_divisible_by(num, den) ? "YES" : "NO");
            n = 0;
        }
    }

    return 0;
}
