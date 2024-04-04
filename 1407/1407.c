// bee 1407 - Loteria de Fim de Semana
// Alonso Martins
// 27/03/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_V = 100

int comparar_i(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}
int comparar(const void *a_, const void *b_){
	const int *a = (const int *)a_;
	const int *b = (const int *)b_;
	return (a[1] - b[1]) * (a[1] != b[1]) + (a[0] - b[0]) * (a[1] == b[1]);
}
int main(int argc, char *argv[])
{
	int N, C, K, i, n, t;
	
	while(1)
	{
		scanf("%d %d %d", &N, &C, &K);
		
		if(N + C + K == 0)
			break;
		
		// armazena a frequencia cada numero.
		int contagem[K][2];
		
		// (índice, frequencia)
		for(i = 0; i < K; i ++)
		{
			contagem[i][0] = i+1;
			contagem[i][1] = 0;
		}

		for(i = 0; i < N*C; i ++)
		{
			scanf("%d", &n);
			contagem[n-1][1]++;
		}
		
		qsort(contagem, K, sizeof (contagem[0]), comparar);
		
		printf("%d", contagem[0][0]);
		for(i = 1; i < K; i ++) {
			if(contagem[i][1] != contagem[i-1][1])
				break;
			printf(" %d", contagem[i][0]);
		}
		printf("\n");
	}
		
	return 0;
}
