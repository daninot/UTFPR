#include <stdio.h>

int main (void)
{
	int P, R, teste=1, i, N, J, k, acoes, j, l;
	
	while(scanf("%d %d",&P,&R) == 2 && (P != 0 && R != 0))
	{
		int vet[P+1];
		
		for(i=0; i<P; i++)
			scanf("%d",&vet[i]);
		
		for(i=0; i<R; i++)
		{
			scanf("%d %d",&N,&J);
			k=0;
			for(j=0; j<N; j++)
			{
				scanf("%d",&acoes);
				if(acoes != J)
				{
					for(l=(k+1); l<N; l++)
						vet[l-1] = vet[l];
				}
				else 
					k++;
			}
		}
		printf("Teste %d\n%d\n\n",teste++,vet[0]);
	}	
	return 0;
}
