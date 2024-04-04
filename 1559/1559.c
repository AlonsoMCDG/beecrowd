// bee 1559 - 2048
// Alonso Martins
// 29/03/2024
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3

int sum(int v[], int t)
{
	int i, sum = 0;
	for (i = 0; i < t; i++)
		sum += v[i];
	return sum;
}

void preencher(int **mat, int linhas, int colunas)
{
	int i, j;
	for (i = 0; i < linhas; i++)
		for (j = 0; j < colunas; j++)
			scanf("%d", &mat[i][j]);
}

void imprimir(int **mat, int linhas, int colunas)
{
	int i, j;
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

int movimentos_validos(int **t, int l, int c)
{
	int i, j, mov[] = {0, 0, 0, 0};

	for (i = 0; i < l; i++)
	{
		for (j = 0; j < c; j++)
		{
			if(t[i][j] >= 2048)
				return 0;
			
			if (t[i][j])
			{
				if (i < 3 && t[i + 1][j] == t[i][j])
					mov[DOWN] = 1;
				if (j > 0 && t[i][j - 1] == t[i][j])
					mov[LEFT] = 2;
				if (j < 3 && t[i][j + 1] == t[i][j])
					mov[RIGHT] = 4;
				if (i > 0 && t[i - 1][j] == t[i][j])
					mov[UP] = 8;
			}
			else
			{
				if (i > 0 && t[i - 1][j])
					mov[DOWN] = 1;
				if (j < 3 && t[i][j + 1])
					mov[LEFT] = 2;
				if (j > 0 && t[i][j - 1])
					mov[RIGHT] = 4;
				if (i < 3 && t[i + 1][j])
					mov[UP] = 8;
			}
		}
	}
	return sum(mov, 4);
}

int main(int argc, char *argv[])
{
	char movimentos[][20] = {"NONE",
				 "DOWN",
				 "LEFT",
				 "DOWN LEFT",
				 "RIGHT",
				 "DOWN RIGHT",
				 "LEFT RIGHT",
				 "DOWN LEFT RIGHT",
				 "UP",
				 "DOWN UP",
				 "LEFT UP",
				 "DOWN LEFT UP",
				 "RIGHT UP",
				 "DOWN RIGHT UP",
				 "LEFT RIGHT UP",
				 "DOWN LEFT RIGHT UP"};

	//printf("%s\n", movimentos[UP]);
	int i, j, T, linhas = 4, colunas = 4;

	scanf("%d", &T);

	int **tabuleiro;

	tabuleiro = (int **)malloc(linhas * sizeof(int *));
	for (j = 0; j < linhas; j++)
		tabuleiro[j] = (int *)malloc(colunas * sizeof(int));

	for (i = 0; i < T; i++)
	{
		preencher(tabuleiro, linhas, colunas);

		printf("%s\n", movimentos[movimentos_validos(tabuleiro, 4, 4)]);

		//imprimir(tabuleiro, linhas, colunas);
	}
	for (j = 0; j < linhas; j++)
		free(tabuleiro[j]);
	free(tabuleiro);
	return 0;
}
