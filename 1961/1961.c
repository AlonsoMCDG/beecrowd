// bee 1961 - Pula Sapo
// Alonso Martins
// 18/03/2024
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int P, N, A, B, W = 1, i;
	scanf("%d %d", &P, &N);
	scanf("%d", &A);
	for (i = 1; i < N && W; i ++)
	{
		scanf("%d", &B);
		W = abs(A - B) <= P;
		A = B;
	}
	printf(W ? "YOU WIN\n"  : "GAME OVER\n");
	return 0;
}
