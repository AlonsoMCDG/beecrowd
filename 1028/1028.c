// bee 1028 - Figurinhas
// Alonso Martins
// 09/04/2024
#include <stdio.h>

int mdc(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int main()
{
    int N, f1, f2, i;

    scanf("%d", &N);

    while (N --)
    {
        scanf("%d %d", &f1, &f2);

        printf("%d\n", mdc(f1, f2));
    }

    return 0;
}
