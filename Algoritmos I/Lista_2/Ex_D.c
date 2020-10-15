#include <stdio.h>

int main (void)
{
	int i, N, fat=1;
	
	scanf("%d",&N);

	for(i=1; i<=N; i++)
	{
		fat = fat * i;
	}

	printf("%d\n",fat);

	return 0;
}
