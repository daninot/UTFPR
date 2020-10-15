#include <stdio.h>

int main (void)
{
	int i=0, N, copos, latas, c=0;
	
	scanf("%d",&N);
	
	while(i < N)
	{
		scanf("%d %d",&latas,&copos);
		
		if(latas > copos)
		{
			c = c + copos;
		}		
		i++;
	}
	printf("%d\n",c);
	
	return 0;
}
