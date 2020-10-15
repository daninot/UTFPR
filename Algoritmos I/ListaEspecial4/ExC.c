#include <stdio.h>

int main (void)
{
	int A, V, teste=1, i, X, Y, maior;
	
	while(scanf("%d %d",&A,&V) == 2 && (A != 0 && V != 0))
	{
		int vet[A];
		
		for(i=1; i<=A; i++)
			vet[i] = 0;
			
		for(i=1; i<=V; i++)
		{
			scanf("%d %d",&X,&Y);
			vet[X]++;
			vet[Y]++;
		}
		
		maior = 0;
		for(i=1; i<=A; i++)		//primeiro encontro o maior tráfego
		{
			if(vet[i] > maior)
				maior = vet[i];
		}
		
		printf("Teste %d\n",teste++);
		
		for(i=1; i<=A; i++)		//agora vejo qual aeroporto tem esse maior tráfego
		{
			if(vet[i] == maior)
				printf("%d ",i);
		}
		printf("\n\n");	
	}
	return 0;
}
