// bee 1030 - A Lenda de Flavious Josephus
// Alonso Martins
// 31/03/2024
#include <stdio.h>
int main(int argc, char *argv[])
{
	int NC, nc, n, k, i, ans;
	
	scanf("%d", &NC);
	
	for(nc = 1; nc <= NC; nc++)
	{
		scanf("%d %d", &n, &k);
    
		ans = 0;
    for(i = 1; i <= n; i ++)
			ans = (ans + k) % i;
			
		printf("Case %d: %d\n", nc, ans+1);
	}
	return 0;
}
