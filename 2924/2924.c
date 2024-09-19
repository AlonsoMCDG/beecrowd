// bee 2924 - BigInt
// Alonso Martins
// 19/09/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_soma(char *A, char *B)
{
    char C[200] = {};
    int sz_a = strlen(A), sz_b = strlen(B);
    int i, soma, carry = 0, sz_c = 0;

    while (sz_a || sz_b)
    {
        if (sz_a) sz_a --;
        if (sz_b) sz_b --;

        soma = A[sz_a] + B[sz_b] - 2 * '0' + carry;
        carry = soma / 10;

        C[sz_c ++] = soma % 10 + '0';
    }

    if (C[sz_c - 1] == '0') sz_c --;

    for (i = sz_c - 1; i >= 0; i --) printf("%c", C[i]);
    printf("\n");
}

int main()
{
    char A[200] = {'0'}, B[200] = {'0'};

    scanf("%s %s", &A[1], &B[1]);

    print_soma(A, B);

    return 0;
}
