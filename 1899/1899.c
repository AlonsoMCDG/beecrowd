// bee 1899 - Acerte o Alvo!
// Alonso Martins
// 30/03/2024
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int N, i, ans = 'Y';
	double D, A, B;
	
	scanf("%d", &N);
	scanf("%lf %lf %lf", &D, &A, &B);
	
	double minA = A / D, minB;
	double maxA = B / D, maxB;
	
	for(i = 1; i <= N; i ++) {
		scanf("%lf %lf %lf", &D, &A, &B);
		
		minA = fmax(minA, A / D);
		maxA = fmin(maxA, B / D);
		
		if(minA > maxA)
		{
			ans = 'N';
			break;
		}
	}
	
	printf("%c\n", ans);
	
	return 0;
}
