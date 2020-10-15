#include <stdio.h>

int main (void)
{
	int N, capacidade, i, S, E, passou=0;
	
	scanf("%d %d",&N,&capacidade);
	
	int dif[N];
	dif[0]=0;
	
	for(i=1; i<=N; i++)
	{
		scanf("%d %d",&S,&E);
		
		dif[i] = (dif[i-1] - S) + E;
		
		if(dif[i] > capacidade)
		{
			passou++;
		}

	}
	if(passou > 0)
	{
		printf("S\n");
	}
	else
	{
		printf("N\n");
	}
	
	return 0;
}
