// bee 1234 - Sentenca Dancante
// Alonso Martins
// 01/05/2024
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sobe (char *s, int i, int size);
void desce(char *s, int i, int size);

void desce(char *s, int i, int size)
{
    if (i == size) return;
    if (s[i] == ' ') desce(s, i + 1, size);
    else {
        s[i] = tolower(s[i]);
        sobe(s, i + 1, size);
    }
}

void sobe(char *s, int i, int size)
{
    if (i == size) return;
    if (s[i] == ' ') 
        sobe(s, i + 1, size);
    else {
        s[i] = toupper(s[i]);
        desce(s, i + 1, size);
    }
}

void mandarParaOBaile(char *s)
{
    sobe(s, 0, strlen(s));
}

int main()
{
    char string[51];

    while (scanf("%50[^\n]%*c", string) != EOF)
    {
        mandarParaOBaile(string);
        printf("%s\n", string);
    }
    
    return 0;
}
