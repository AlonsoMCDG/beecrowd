// bee 3050 - Distância Entre Amigos
// Alonso Martins
// 18/03/2024
#include <stdio.h>
int main(int argc, char *argv[])
{
	int n, d, maxD = 0, i, j;
	scanf("%d", &n);
	int p[n];
	for(i = 0; i < n; i ++) 
	{
		scanf("%d", &p[i]);
	}
	for (i = 0; i < n - 1; i ++)
	{
		for (j = i + 1; j < n; j ++)
		{
			d = p[i] + (j - i) + p[j];
			maxD = d > maxD ? d : maxD;
		}
	}
	printf("%d\n", maxD);
	return 0;
}
