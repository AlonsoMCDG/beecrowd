// bee 3060 - Parcelamento Sem Juros
// Alonso Martins
// 18/03/2024
#include <stdio.h>

int main(int argc, char *argv[])
{
	int V, P, R, C, D, i;
	scanf("%d %d", &V, &P);
	R = V % P;
	D = V / P;
	for (i = 0; i < P; i ++, R--)
	{
		C = D + (R > 0);
		printf("%d\n", C);
	}
	return 0;
}
