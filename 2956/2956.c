// bee 2956 - Derivada de 13 Variaveis
// Alonso Martins
// 06/06/2024
#include <stdio.h>
int main(int argc, char *argv[])
{
	double area, base, altura;
	
	scanf("%lf %lf", &base, &altura);
	area = base * altura / 2.0;
	printf("Concluimos que, dado o limite da entrada, a resposta seria:  y = f(x) = %.5lf.\n", area);
	
	return 0;
}
