// bee 2434 - Saldo do Vovô
// Alonso Martins
// 18/03/2024
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int M, S, N, O;
	scanf("%d %d", &N, &S);
	M = S;
	for (int i = 0; i < N; i ++)
	{
		scanf("%d", &O);
		S += O;
		M = fmin(M, S);
	}
	printf("%d\n", M);
	return 0;
}
