// bee 1088 - Bolhas e Baldes
// Alonso Martins
// 22/11/2024
#include <stdio.h>

#define MAX_N 100000

int merge(int *v, int temp[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start, count = 0;

    while (i <= mid && j <= end)
    {
        if (v[j] < v[i])
        {
            temp[k ++] = v[j ++];
            count += (mid - i + 1);
        }
        else temp[k ++] = v[i ++];
    }

    while (i <= mid)
        temp[k ++] = v[i ++];

    while (j <= end)
        temp[k ++] = v[j ++];

    for (i = start; i <= end; i ++)
        v[i] = temp[i];

    return count;
}

int merge_sort(int *v, int *temp, int start, int end)
{
    int mid, count = 0;

    if (start < end)
    {
        mid = (start + end) / 2;
        count += merge_sort(v, temp, start, mid);
        count += merge_sort(v, temp, mid + 1, end);
        count += merge(v, temp, start, mid, end);
    }

    return count;
}

int inversions(int *v, int n)
{
    int temp[MAX_N];
    return merge_sort(v, temp, 0, n - 1);
}

int main()
{
    int N, i, v[MAX_N];

    while (scanf("%d", &N), N)
    {
        for (i = 0; i < N; i ++)
            scanf("%d", &v[i]);
        
        printf("%s\n", inversions(v, N) & 1 ? "Marcelo" : "Carlos");
    }

    return 0;
}

