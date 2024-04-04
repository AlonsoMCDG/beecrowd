// bee 1087 - Dama
// Alonso Martins
// 01/04/2024
#include <stdio.h>
int main(int argc, char *argv[])
{
	int x1=0, y1=0, x2=0, y2=0;
	while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) && (x1 + y1 + x2 + y2))
	{
		if (x1 == x2 && y1 == y2)
			printf("0\n");
		else if (x1 == x2 || y1 == y2 || y1 - x1 == y2 - x2 || x1 + y1 == x2 + y2)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}
