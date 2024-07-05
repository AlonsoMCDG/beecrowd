// bee 1650 - Pintura Preto e Branco
// Alonso Martins
// 04/07/2024
#include <stdio.h>

typedef long long ll;

ll solve(ll n, ll m)
{
	ll L = ((n - n % 2) / 2) - 3;
	ll C = ((m - m % 2) / 2) - 3;
	return L * C;
}

int main()
{
	ll N, M, C;
	
	while (scanf("%lld %lld %lld", &N, &M, &C), N)
	{
		ll ans = 0;
		
		if (C == 1)
			ans = solve(N, M) + solve(N - 1, M - 1);
		else
			ans = solve(N + 1, M) + solve(N, M - 1) - ((M - M % 2) / 2 - 3);
			
		printf("%lld\n", ans);
	}
	
	return 0;
}
