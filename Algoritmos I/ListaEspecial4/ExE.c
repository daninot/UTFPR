#include <stdio.h>		//não deu certo
#include <stdlib.h>
#include <string.h>

int main (void)
{
	int N, menor, K, tipinho, i, j;
	
	scanf("%d %d",&N,&K);
	
	int tipos[K+1];
	memset(tipos,0,sizeof(tipos));
	menor = N;
	for(i=0; i<N; i++)
	{
		scanf("%d",&tipinho);
		
		for(j=1; j<=K; j++)
		{
			if(tipinho == j)
				tipos[j]++;
		}
	}
	for(j=1; j<=K; j++)
	{
		if(tipos[j] < menor)
			menor = tipos[j];
	}
	printf("%d\n",menor);
	
	return 0;
}
