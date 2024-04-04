// bebê 2444 - Volume da TV
// Alonso Martins
// 27/03/2024
#include<stdio.h>
int main(int argc, char *argv[])
{
	int V, T, i, t;
	scanf("%d %d", &V, &T);
	for(i = 0; i < T; i ++)
	{
		scanf("%d", &t);
		V += t;
		V = V > 100 ? 100 : V * !(V < 0);
	}
	printf("%d\n", V);
	return 0;
}
