// HOMEWORK: Funções e recursividade
// bee 1025 - Onde está o Mármore?
// Alonso Martins
// 29/04/2024
#include <stdio.h>
#include <stdlib.h>

#define dbg(x) printf("#x = %d\n", x);

int comparar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int search(int *v, int value, int l, int r)
{
    if (r < 0 || l > r) return -1;
    if (l == r || value == v[l]) return value == v[l] ? l : -1;
    
    int z, m, s;

    m = (l + r) / 2 + (l + r) % 2;
    
    if (value > v[m])
        return search(v, value, m + 1, r);

    s = search(v, value, l, m - 1);
    
    return s + 1 ? s : value == v[m] ? m : -1;
}
int main()
{
    int N, Q, i, caso = 0, x, index;
    int marbles[10001];
    while (scanf("%d %d", &N, &Q) && N + Q && ++caso)
    {

        for (i = 0; i < N; i++)
            scanf("%d", &marbles[i]);

        qsort(marbles, N, sizeof(int), comparar);

        printf("CASE# %d:\n", caso);
        
        for (i = 0; i < Q; i++)
        {
            scanf("%d", &x);
            index = search(marbles, x, 0, N - 1);
            printf(index != -1 ? "%d found at %d\n" : "%d not found\n", x, index + 1);
        }
    }
    return 0;
}
