// bee 1401 - Gerando Permutacoes Ordenadas Rapidamente
// Alonso Martins
// 29/09/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b)
{
    return *(const char *)a - *(const char *)b;
}

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void reverse(char *s, int n)
{
    int i = n / 2 - 1;
    while (i ++ < n - 1)
        swap(&s[i], &s[n - i - 1]);
}

int next_permutation(char *seq)
{
    int i = -1, j = 0, k;

    for (k = 0; seq[k]; k ++)
        if (seq[k] < seq[k + 1])
            i = k;
    
    if (i == -1) return -1;

    for (k = 0; seq[k]; k ++)
        if (seq[k] > seq[i])
            j = k;
    
    swap(&seq[i], &seq[j]);

    reverse(&seq[i + 1], k - i - 1);
}

int main()
{
    int N, i, j;
    char seq[12];

    scanf("%d", &N);

    while (N -- && scanf(" %s", seq))
    {
        qsort(seq, strlen(seq), sizeof(seq[0]), comp);
        do
            printf("%s\n", seq);
        while (next_permutation(seq) != -1);
        printf("\n");
    }

    return 0;
}
