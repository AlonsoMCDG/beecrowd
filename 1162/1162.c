// bee 1162 - Organizador de Vagoes
// Alonso Martins
// 24/11/2024
#include <stdio.h>

#define MAX 50

int merge(int *arr, int *temp, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left, count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[j] < arr[i])
        {
            count += (j - k);
            temp[k ++] = arr[j ++];
        }
        else
            temp[k ++] = arr[i ++];
    }

    while (i <= mid)
        temp[k ++] = arr[i ++];
    while (j <= right)
        temp[k ++] = arr[j ++];
    
    for (i = left; i <= right; i ++)
        arr[i] = temp[i];

    return count;
}

int merge_sort(int *arr, int *temp, int left, int right)
{
    int i, mid, count = 0;

    if (left < right)
    {
        mid = (left + right) / 2;
        count += merge_sort(arr, temp, left, mid);
        count += merge_sort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid, right);
    }

    return count;
}

int main()
{
    int T, N, i, arr[MAX], temp[MAX];

    scanf("%d", &T);

    while (T -- && scanf("%d", &N))
    {
        for (i = 0; i < N; i ++)
            scanf("%d", &arr[i]), temp[i] = arr[i];

        printf("Optimal train swapping takes %d swaps.\n", merge_sort(arr, temp, 0, N - 1));
    }

    return 0;
}
