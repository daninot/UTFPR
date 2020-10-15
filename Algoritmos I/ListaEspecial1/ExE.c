#include <stdio.h>

int main(void)
{
	int A, a, B, b, C, c, X, Y, Z, qtd; 

	scanf("%d %d %d",&A,&B,&C);
	scanf("%d %d %d",&a,&b,&c);

	X = a / A;
	Y = b / B;
	Z = c / C;

	qtd = X * Y * Z;
		
	printf("%d\n",qtd);

	return 0;
}
