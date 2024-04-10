// bee 1045 - Tipos de Triângulos
// Alonso Martins
// 26/01/2023
#include <stdio.h>
double A, B, C;
void ordenar() {
    if (A < B) { double temp = A; A = B; B = temp; }
    if (A < C) { double temp = A; A = C; C = temp; }
}
int main() {
    scanf("%lf %lf %lf", &A, &B, &C);
    ordenar();
    if(A >= B + C) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        if(A * A == B * B + C * C) {
            printf("TRIANGULO RETANGULO\n");
        } else if(A * A > B * B + C * C) {
            printf("TRIANGULO OBTUSANGULO\n");
        } else {
            printf("TRIANGULO ACUTANGULO\n");
        }
        if(A == B && B == C) {
            printf("TRIANGULO EQUILATERO\n");
        } else if(A == B || A == C || B == C){
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    return 0;
}
