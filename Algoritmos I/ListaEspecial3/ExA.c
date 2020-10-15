#include <stdio.h>

int main (void)
{
	int N, n, i, j=1;
	
	scanf("%d",&N);
	while(N > 0)
	{
		i=1;
		while(i <= N)
		{	
			scanf("%d",&n);		
			if(i == n)
			{
				printf("Teste %d\n%d\n\n",j,n);
			}
			i++;
		}
		scanf("%d",&N);
		j++;	
	}

	return 0;
}
