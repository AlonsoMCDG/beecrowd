// bee 3303 - Palavrao
// Alonso Martins
// 20/02/2024
#include <stdio.h>
#include <string.h>

int main() {
    char s[20];
    
    fgets(s, 20, stdin);
    
    printf(strlen(s) >= 10 ? "palavrao\n" : "palavrinha\n");
    
    return 0;
}
