// bee 3106 - Competicao de Codigos
// Alonso Martins
// 08/06/2024
#include <stdio.h>

int main()
{
    int N, ans = 0, A;

    scanf("%d", &N);

    while (N -- && scanf("%d", &A))
        ans += A / 3;
    
    printf("%d\n", ans * 3);

    return 0;
}
