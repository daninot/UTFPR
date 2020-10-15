#include <stdio.h>

int main (void)
{
    	int N, i, beto=0, alice=0, resultados[N];
	
	do
	{
		scanf("%d",&N);
		
		for(i=1; i<=N; i++)
		{
			scanf("%d",&resultados[i]);

			if(resultados[i] == 0)
			{
				alice++;
			}
			else
			{
				beto++;
			}
		}

	}while(N != 0);
	
	printf("Alice ganhou %d e Beto ganhou %d\n",alice,beto);

	return 0; 
}


