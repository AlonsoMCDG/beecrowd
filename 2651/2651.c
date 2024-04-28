// bee 2651 - Link Bolado
// Alonso Martins
// 28/04/2024
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char carta[100002];
    int i;

    scanf("%s", carta);

    for (i = 0; i < strlen(carta); i ++)
        carta[i] = tolower(carta[i]);

    printf(strstr(carta, "zelda") == NULL ? "Link Tranquilo\n" : "Link Bolado\n");

    return 0;
}
