// bee 3346 - Flutuacao do PIB
// Alonso Martins
// 20/02/2024
#include <stdio.h>
#include <math.h>

int main() 
{
    double f, f1, f2;
    
    scanf("%lf %lf", &f1, &f2);
    
    f = ((((1.0 + f1/100.00) * (1.0 + f2/100.00)) - 1.0) * 100.0);
    
    printf("%.6lf\n", f);
    return 0;
}
