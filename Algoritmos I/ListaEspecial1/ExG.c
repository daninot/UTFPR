#include <stdio.h>

int main(void)
{
	int Ateste, prox=2062, resultado;

	scanf("%d",&Ateste);
	
	resultado = prox - Ateste;
	
	while(resultado <= 0)	
	{
		prox = prox + 76;
		resultado = prox - Ateste;
	}

	printf("%d\n",prox);		

	return 0;
}
