#include <stdio.h>

int main (void)
{
	int N, divisores=0, i;
	
	scanf("%d",&N);
		
	for(i=2; i<=N/2; i++)
	{
		if(N % i == 0)
		{
			divisores++;
		}
	}
	if(divisores == 0)
	{
		printf("sim\n");
	}
	else
	{
		printf("nao\n");
	}
	

	return 0;
}
