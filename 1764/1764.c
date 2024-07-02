// bee 1764 - Itinerario do Papai Noel
// Alonso Martins
// 01/07/2024
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define debug if (DEBUG)

typedef struct Edge
{
	int A;
	int B;
	int dist;
} Edge;

int comp(const void *a, const void *b)
{
	Edge *A = (Edge *)a, *B = (Edge *)b;
	return A->dist - B->dist;
}

int find(int nodes[], int x) {
    if (nodes[x] != x)
        nodes[x] = find(nodes, nodes[x]);
    return nodes[x];
}

int main()
{
	int N, M, i, j, X, Y, Z, conecta;

	while (scanf("%d %d", &M, &N), N && M)
	{
	    Edge edges[50010];
	    
		for (i = 0; i < N; i ++)
		{
			scanf("%d %d %d", &X, &Y, &Z);
			edges[i].A = X;
			edges[i].B = Y;
			edges[i].dist = Z;
		}
		
		int nodes[40010];
		int rank[40000] = {};
		unsigned int ans = 0;
		
		for (i = 0; i < M; i ++) nodes[i] = i;
		
		qsort(edges, N, sizeof(edges[0]), comp);
		
		for (i = 0; i < N; i ++)
		{
			X = edges[i].A;
			Y = edges[i].B;
			Z = edges[i].dist;
			
			int root1 = find(nodes, X);
			int root2 = find(nodes, Y);
			
			if (root1 != root2)
			{
				nodes[root2] = root1;
				ans += Z;
			}
		}
		
		debug printf("--------\n");
		debug for (i = 0; i < N; i ++) printf("%d:%d\n", i, nodes[i]);
		printf("%u\n", ans);
	}

	return 0;
}
