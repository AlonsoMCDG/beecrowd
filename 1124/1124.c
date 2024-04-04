// 1124 - Elevador
// Alonso Martins
// 13/03/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int C, L, R1, R2;
    int x1, y1, x2, y2;
    double d;

    scanf("%d %d %d %d", &C, &L, &R1, &R2);
    
    while (C + L + R1 + R2 != 0)
    {
        x1 = R1     ; y1 = R1    ;
        x2 = C - R2 ; y2 = L - R2;
        
        d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        
        printf("%s\n", d < R1 + R2 || C < 2 * R1 || C < 2 * R2 || L < 2 * R1 || L < 2 * R2 ? "N" : "S");
        
        scanf("%d %d %d %d", &C, &L, &R1, &R2);
    }
    return 0;
}
