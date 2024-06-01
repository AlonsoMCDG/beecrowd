// bee 2435 - Corrida
// Alonso Martins
// 01/06/2024
#include <stdio.h>

int main()
{
    int n1, n2, d, v;
    double t1, t2;

    scanf("%d %d %d", &n1, &d, &v);
    t1 = d / (v / 3.6);

    scanf("%d %d %d", &n2, &d, &v);
    t2 = d / (v / 3.6);

    printf("%d\n", t1 < t2 ? n1 : n2);

    return 0;
}
