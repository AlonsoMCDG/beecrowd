// bee 1629 - DescompactaFACE
// Alonso Martins
// 18/07/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, sz;
    char in[1002];

    while (scanf("%d", &N), N)
    {
        while (N -- && scanf(" %s", in))
        {
            int count[2] = {}, ans = 0;

            for (i = 0, sz = strlen(in); i < sz; i ++)
                count[(i + 1) % 2] += (in[i] - '0');

            for (i = 0; i < 2; i ++)
                while (count[i])
                {
                    ans += count[i] % 10;
                    count[i] /= 10;
                }

            printf("%d\n", ans);
        }
    }

    return 0;
}
