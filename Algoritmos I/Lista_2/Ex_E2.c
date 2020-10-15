#include <stdio.h>

int Funcao91 (int N)
{
	if(N > 100)
	{	
		return(N-10);
	}
	else
	{
		return(Funcao91(Funcao91(N+11)));
	}
}

int main (void)
{
	int N,R;
	
	while(scanf("%d",&N) && N != 0)
	{
		printf("f91(%d) = %d\n",N,Funcao91(N));
	}
	
	return 0;
}
