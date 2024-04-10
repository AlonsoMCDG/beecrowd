// bee 1024 - Criptografia
// Alonso Martins
// 09/04/2024
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 1002

int main()
{
    int T, i, len;
    char txt[MAX_LEN], saida[MAX_LEN], c;

    scanf("%d ", &T);

    while (T --)
    {
        fgets(txt, MAX_LEN, stdin);
        
        txt[strlen(txt) - 1] = '\0';
        
        len = strlen(txt); 
        
        for (i = len - 1; i + 1; i --)
        {
            c = isalpha(txt[i]) ? txt[i] + 3 : txt[i];
            
            printf("%c", i < len / 2 + len % 2 ? c - 1 : c);
        }
        
        printf("\n");
    }

    return 0;
}
