#include <stdio.h>

int main (void)
{
	int N, N2, resto;
	
	scanf("%d %d",&N,&N2);
	
	resto = N % N2;
	
	printf("%d\n",resto);
	 
	return 0;
}
