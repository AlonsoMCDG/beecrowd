// bee 3152 - Samuel, O Cafeicultor
// Alonso Martins
// 07/04/2024
#include <stdio.h>
#include <math.h>

double calcular_area(int p[4][2])//p[][2])
{
    double x1 = p[0][0], y1 = p[0][1];
    double x2 = p[1][0], y2 = p[1][1];
    double x3 = p[2][0], y3 = p[2][1];
    double x4 = p[3][0], y4 = p[3][1];
    
    return 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - y1 * x2 - y2 * x3 - y3 * x4 - y4 * x1);
}

int main()
{
    int A[4][2], B[4][2], i;
    double areaA, areaB;
    
    for (i = 0; i < 4; i ++) scanf("%d %d", &A[i][0], &A[i][1]);
    for (i = 0; i < 4; i ++) scanf("%d %d", &B[i][0], &B[i][1]);
    
    areaA = calcular_area(A);
    areaB = calcular_area(B);
    
    printf("terreno %s\n", areaA > areaB ? "A" : "B");
    
    return 0;
}
