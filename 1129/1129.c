// bee 1129 - Leitura Otica 
// Alonso Martins
// 27/03/2024
#include <stdio.h>
int leitura(int *o)
{
	int i, op = 0;
	for (i = 0; i < 5; i ++)
	{
		if (o[i] <= 127 && op)
			return '*';
		if (o[i] <= 127)
			op = i+1;
	}
	return op ? (op - 1) + 'A' : '*';
}
int main(int argc, char *argv[])
{
	int i, j, N = 1, opcoes_marcadas[5], alternativa;
	scanf("%d", &N);
	while (N)
	{
		for (i = 0; i < N; i ++)
		{
			for (j = 0; j < 5; j ++)
				scanf("%d", &opcoes_marcadas[j]);
			alternativa = leitura(opcoes_marcadas);
			printf("%c\n", alternativa);
		}
		scanf("%d", &N);
	}
	return 0;
}
