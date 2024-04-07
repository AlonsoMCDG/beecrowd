// bee 1022 - TDA Racional
// ALonso Martins
// 07/04/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int den;
} frac;
int mdc(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
frac soma(frac a, frac b, int sinal)
{
    frac r;
    r.num = a.num * b.den + sinal * b.num * a.den;
    r.den = a.den * b.den;
    return r;
}
frac produto(frac a, frac b, int ehProd)
{
    frac r;
    r.num = ehProd * (a.num * b.num) + !ehProd * (a.num * b.den);
    r.den = ehProd * (a.den * b.den) + !ehProd * (b.num * a.den);
    return r;
}
frac simplificarFrac(frac f)
{
    int MDC = mdc(f.num, f.den);
    f.num = f.num / abs(MDC);
    f.den = f.den / abs(MDC);
    return f;
}
void imprimeFrac(frac f, char *end)
{
    printf("%d/%d%s", f.num, f.den, end);
}
int main()
{
    int T;
    char op, d;
    int N1, D1, N2, D2;
    
    scanf("%d", &T);
    
    frac A, B, res;

    while (T --)
    {
        scanf("%d %c %d %c %d %c %d", &A.num, &d, &A.den, &op, &B.num, &d, &B.den);

        res = op == '+' || op == '-' ? soma(A, B, op == '+' ? 1 : -1) : produto(A, B, op == '*');

        imprimeFrac(res, " = ");
        res = simplificarFrac(res);
        imprimeFrac(res, "\n");
    }
    return 0;
}
