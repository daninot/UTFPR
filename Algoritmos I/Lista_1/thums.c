#include <stdio.h>

int main (void)
{
	int N, i;
	
	scanf("%d",&N);

	for(i=1; i<=N; i++)
	{
		if(i % 2 == 0)
		{
			printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
		}	
		else
		{
			printf("THUMS THUMS THUMS\n");
		}
	}	
	
	return 0;
}
