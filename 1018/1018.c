// bee 1018 - Cedulas
// Alonso Martins
// 03/07/2022
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int notas[7] = {
        100, 50, 20, 10, 5, 2, 1
    };
    char cedulas[7][10] = {
        "100,00",
        "50,00",
        "20,00",
        "10,00",
        "5,00",
        "2,00",
        "1,00"
    };
    printf("%d\n", n);
    for (int i = 0; i < 7; i ++) {
        printf("%d nota(s) de R$ %s\n", (n/notas[i]), cedulas[i]);
        n %= notas[i];
    }
    return 0;
}
