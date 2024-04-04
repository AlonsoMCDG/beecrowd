// bee 1026 - Carrega ou nao Carrega?
// Alonso Martins
// 29/03/2024
#include<stdio.h>
int main(int argc, char *argv[])
{
	unsigned int a, b;
	
	while(scanf("%u %u", &a, &b) != EOF)
	{
		printf("%u\n", a^b);
	}
	return 0;
}
