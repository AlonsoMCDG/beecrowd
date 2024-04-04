// bee 1732 - Abelha Maja
// Alonso Martins
// 30/03/2024
#include <stdio.h>
#define X 0
#define Y 1

int main(int argc, char *argv[])
{
	int coords[100001][2] = {};
	coords[2][Y] = 1;
	int i, N, calculados = 2;
	int contCurva = 1;
	int sinalA = -1, sinalB = 0;
	//int contSinalA = 0, contSinalB = 0;
	int contDirecao = 0;
	int prev[2] = {0, 0};
	int totalCamada = 6;
	int camada = 1, contCamada = 1;
	int direcoes[6][2] = {{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}, {-1, 1}};

	while (scanf("%d", &N) != EOF)
	{
		if (N <= calculados)
		{
			printf("%d %d\n", coords[N][X], coords[N][Y]);
			continue;
		}

		for (i = calculados + 1; i <= N; i++)
		{
			coords[i][X] = coords[i - 1][X] + sinalA;
			coords[i][Y] = coords[i - 1][Y] + sinalB;

			contCamada++;
			if (contCamada % camada == 0 || contCamada == 1)
			{
				if (contCamada != totalCamada)
				{
					contDirecao = (contDirecao + 1) % 6;

					sinalA = direcoes[contDirecao][X];
					sinalB = direcoes[contDirecao][Y];
				}
				else
				{
					camada++;
					totalCamada = camada * 6;
					contCamada = 0;
				}
			}
		}

		printf("%d %d\n", coords[N][X], coords[N][Y]);
		calculados = N;

		/*printf("Calculados:\n");
		for(i = 1; i <= calculados; i ++)
			printf("%d: (%d, %d), ", i, coords[i][X], coords[i][Y]);
		printf("\n\n");//*/
	}
	return 0;
}
