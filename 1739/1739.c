// bee 1739 - Sequencia de Threebonacci
// Alonso Martins
// 12/09/2024
#include <stdio.h>

long long ans[60] = {};
int cont = 0;

void threebonacci()
{
    long long f1 = 1, f2 = 2, f3, n;

    while (cont < 60)
    {
        f3 = f1 + f2;

        if (f3 % 3 == 0)
        {
            ans[cont ++] = f3;
        }
        else
        {
            n = f3;
            while (n)
            {
                if (n % 10 == 3)
                {
                    ans[cont ++] = f3;
                    break;
                }
                n /= 10;
            }
        }

        f1 = f2;
        f2 = f3;
    }
}

int main()
{
    int N;
    threebonacci();

    while (scanf("%d", &N) != EOF)
        printf("%lld\n", ans[N - 1]);

    return 0;
}
