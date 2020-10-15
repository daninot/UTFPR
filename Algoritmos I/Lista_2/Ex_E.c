#include <stdio.h>

void Funcao91 (int N)
{
	if(N == 0)
	{
		return;
	}
	if(N > 100)
	{	
		printf("f91(%d) = %d\n",N,N-10);
	}
	else
	{
		printf("f91(%d) = 91\n",N);
	}
}

int main (void)
{
	int N;
	
	while(scanf("%d",&N) && N != 0)
	{
		printf("%d",N);
		Funcao91(N);
	}
	
	return 0;
}
