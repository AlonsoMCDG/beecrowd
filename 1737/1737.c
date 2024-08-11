// bee 1737 - Etaoin Shrdlu
// Alonso Martins
// 11/08/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Digrafo
{
	char item[3];
	int frequencia;
} Digrafo;

int comp_s(const void *a, const void *b)
{
	Digrafo *A = (Digrafo *)a, *B = (Digrafo *)b;

	return strcmp(A->item, B->item);
}

int comp_d(const void *a, const void *b)
{
	Digrafo *A = (Digrafo *)a, *B = (Digrafo *)b;

	return 6000 * (B->frequencia - A->frequencia) + strcmp(A->item, B->item);
}

int main()
{
	int N, i, sz;

	while (scanf("%d%*c", &N), N)
	{
		char texto[5200] = {};
		char linha[82];

		for (i = 0; i < N; i ++)
		{
			scanf("%80[^\n]%*c", linha);
			strcat(texto, linha);
		}
		sz = strlen(texto) - 1;
		Digrafo digrafos[sz];

		for (i = 0; i < sz; i ++)
		{
			digrafos[i].item[0] = texto[i];
			digrafos[i].item[1] = texto[i + 1];
			digrafos[i].item[2] = '\0';
			digrafos[i].frequencia = 0;
		}

		qsort(digrafos, sz, sizeof(digrafos[0]), comp_s);

		int j = 0;
		for (i = 0; i < sz; i ++)
		{
			if (strcmp(digrafos[i].item, digrafos[j].item) != 0)
				j = i;
			digrafos[j].frequencia ++;
		}

		qsort(digrafos, sz, sizeof(digrafos[0]), comp_d);

		int aux = (int)fmin(5, sz);
	
		for (i = 0; i < aux; i ++)
			printf("%s %d %.6lf\n", digrafos[i].item, digrafos[i].frequencia, 1.0 * digrafos[i].frequencia / sz);

		printf("\n");
	}

	return 0;
}
