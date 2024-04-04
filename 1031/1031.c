// bee 1031 - Crise de Energia
// Alonso Martins
// 31/03/2024
#include <stdio.h>
int main(int argc, char *argv[])
{
	int i, a,
		N, // quantidade de divisoes, numeradas de 0 a N-1
		K, // tamanho do salto
		F, // posições removidas antes de S
		S, // índice do "13" na sequencia
		R, // quantidade de posicoes removidas na iteracao
		L, // quantidade de posições restantes no fim da sequencia
		T, // tamanho da sequencia na iteracao
		P, // ponto inicial na iteracao
		m; // resposta

	while (scanf("%d", &N) && N)
	{
		if (N == 13)
		{
			printf("1\n");
			continue;
		}

		m = 0;
		for (K = 5; !m; K++)
		{
			T = N; P = 0; S = 12; a = 1;
			//printf("K = %d\n", K);
			//printf("T = %d\n", T);
			//printf("S = %d\n", S);
			//printf("P = %d\n", P);
			//printf("\n");
			while ((S - P) % K)
			{
				//printf("A%d:\n", a++);
				//printf("T = %d\n", T);
				//printf("P = %d\n", P);
				//printf("S = %d\n", S);
				
				F = (S - P) / K + (S > P);
				S = S - F;
				R = (T - 1 - P) / K + 1;
				L = (T - 1 - P) % K;
				T = T - R;
				P = (K - 1 - L) % T;
				
				//printf("F = %d\n", F);
				//printf("R = %d\n", R);
				//printf("L = %d\n", L);
				
				//printf("******\n");
				//scanf("%d", &i);
			}
			//printf("A%d:\n", a);
			//printf("T = %d, P = %d, S = %d\n", T, P, S);
			
			if(T == 1)
				m = K;
			
			//printf("T == 1 ? %c\n", T == 1 ? 'S' : 'N');
			//scanf("%d", &i);
		}

		printf("%d\n", m);
	}
	return 0;
}
