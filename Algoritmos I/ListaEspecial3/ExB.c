#include <stdio.h>

int main (void)
{
	short int N, x=1, i, J, Z;
	
	scanf("%hi",&N);
	
	while(N > 0)
	{
		short int dif[N], aux=0;
		
		scanf("%hi %hi",&J,&Z);
		dif[0] = J - Z + aux;
		
		for(i=1; i<N; i++)
		{
			aux = dif[i-1];
			scanf("%hi %hi",&J,&Z);
			dif[i] = J - Z + aux;
		}
		
		printf("Teste %hi\n",x);
		
		for(i=0; i<N; i++)
		{
			printf("%hi\n",dif[i]);
		}
		
		printf("\n");
		x++;
		scanf("%hi",&N);
	}
	return 0;
}
