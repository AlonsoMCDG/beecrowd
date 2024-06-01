// bee 2349 - Farm Robot
// Alonso Martins
// 01/06/2024
#include <stdio.h>

int main()
{
    int N, i, C, S, p, r = 0, ans;

    scanf("%d %d %d", &N, &C, &S), S --;
    
    for (i = 0, ans = (r == S); i < C && scanf("%d", &p); i ++)
        ans += ((r = (N + r + p) % N) == S);
    
    printf("%d\n", ans);

    return 0;
}
