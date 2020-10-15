#include <stdio.h>

int main (void)
{
	int V, I, J, K, L, i=1;
	
	while(scanf("%d",&V) == 1 && V != 0)
	{		
		I = V / 50;
		J = (V - (50*I)) / 10;
		K = ((V - (50*I)) % 10) / 5;
		L = V - (I*50) - (J*10) - (K*5);
		
		printf("Teste %d\n%d %d %d %d\n\n",i,I,J,K,L);
		
		i++;
	}
	
	return 0;
}
