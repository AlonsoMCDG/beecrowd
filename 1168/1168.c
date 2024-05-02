// bee 1168 - LED
// Alonso Martins
// 01/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int T, i, ans;
    char n[101];

    scanf("%d%*c", &T);

    while (T --)
    {
        scanf("%s", n);
        ans = 0;

        for (i = 0; i < strlen(n); i ++)
            ans += leds[n[i] - '0'];
        
        printf("%d leds\n", ans);
    }

    return 0;
}
