#include <stdio.h>

int main (void)
{
	short int N, dif, x=1, i, J, Z, j;
	scanf("%hi",&N);
	short int v[N+1];
	while(N != 0)
	{
		dif=0;
		printf("Teste %hi\n",x);
		for(i=1; i<=N; i++)
		{
			scanf("%hi %hi",&J,&Z);
			dif = dif + (J - Z);
			
			printf("%hi\n",dif);
		}	
		printf("\n");
		x++;
		scanf("%hi",&N);
	}
	return 0;
}
