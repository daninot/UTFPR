#include <stdio.h>

int main (void)
{
	int N, X, i, soma=0;
	
	scanf("%d",&N);
	
	for(i=0; i<N; i++)
	{
		scanf("%d",&X);
		
		soma = soma + X;	
	}
	
	printf("%d\n",soma);

	return 0;
}
