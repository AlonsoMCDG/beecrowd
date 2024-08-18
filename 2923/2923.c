// bee 2923 - Birinho
// Alonso Martins
// 18/08/2024
#include <stdio.h>

int main()
{
    int total, usado, warning, critical;

    while (scanf("%d %d %d %d", &total, &usado, &warning, &critical) != EOF)
    {
        double p = 100.0 * usado / total;

        if (p >= critical) printf("critical\n");
        else if(p >= warning) printf("warning\n");
        else printf("OK\n");
    }

    return 0;
}
