// bee 2464 - Decifra
// Alonso Martins
// 07/07/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int i, sz;
    char cifra[30], alfabeto[30], decifra[10002];

    scanf(" %s", cifra);

    for (i = 0; i < 26; i ++)
        alfabeto[cifra[i] - 'a'] = i + 'a';

    scanf(" %s", decifra);

    for (i = 0, sz = strlen(decifra); i < sz; i ++)
        decifra[i] = alfabeto[decifra[i] - 'a'];

    printf("%s\n", decifra);

    return 0;
}
