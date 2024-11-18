// bee 1398 - Oceano Profundo! Faca-o Raso!!
// Alonso Martins
// 16/11/2024
#include <stdio.h>
#include <string.h>

#define ord(x) ((x) - '0')
#define chr(x) ((x) + '0')

int bin_to_dec(char *bin)
{
    if (strlen(bin) >= 32) return -1;

    int n = 0, c, i = 0;

    for (c = bin[i]; c; c = bin[++ i])
    {
        n <<= 1;
        n |= (c == '1');
    }

    return n;
}

// remove todos os caracteres 'c' do início de 'str'
int lstrip(char *str, char c)
{
    int i = 0, j = 0;
    while (str[i] == c) i ++;
    while (str[i]) str[j ++] = str[i ++];
    if (i == 0) return; // a string nao começa com o caractere
    if (j == 0) str[j ++] = '0';
    str[j] = '\0';
    return j;
}

// subtracao binária. op1 = op1 - op2 (op1 precisa ser maior ou igual a op2)
void sub(char *op1, char *op2)
{
    int s1 = strlen(op1), s2 = strlen(op2), i, j, c = 0, b = 0, r, ax, bx;

    for (i = 0; i < s1; i++)
    {
        ax = op1[s1 - i - 1] - c;
        bx = (s2 - i > 0 ? op2[s2 - i - 1] : '0');
        b = ax < bx; // flag borrow
        
        op1[s1 - i - 1] = chr(ax + 2 * b - bx);
        c = b; // carry
    }
}

int is_divisible_by(char *numerator, char *denominator)
{
    char quotient[10500] = {}, div;
    char remainder[50] = {};
    int r_sz = 0, q_sz = 0, d_sz = strlen(denominator), n_sz = strlen(numerator), n_count = 0, flag = 0;

    while (1)
    {
        if (n_count == n_sz) break;
        
        flag = 0;
        while (numerator[n_count] && r_sz < d_sz)
        {
            if (remainder[0] == '0' && r_sz == 1) r_sz --;
            remainder[r_sz ++] = numerator[n_count ++];
            if (flag ++) quotient[q_sz ++] = '0';
        }
        
        if (r_sz == d_sz && strcmp(remainder, denominator) < 0 && numerator[n_count])
        {
            remainder[r_sz ++] = numerator[n_count ++];
            if (flag) quotient[q_sz ++] = '0';
        }
        remainder[r_sz] = '\0';

        if (r_sz < d_sz)
        {
            quotient[q_sz ++] = '0';
            break;
        }

        sub(remainder, denominator);
        quotient[q_sz ++] = '1';

        q_sz = lstrip(quotient, '0');
        r_sz = lstrip(remainder, '0');
    }

    // printf("quotient  : [%s]\t= %4d\n", quotient, bin_to_dec(quotient)); // debug
    // printf("remainder : [%s]\t= %4d\n", remainder, bin_to_dec(remainder)); // debug

    return !strcmp(remainder, "0");
}

int main()
{
    int n = 0;
    char c, num[10502], den[102] = "11111111111111111";

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
