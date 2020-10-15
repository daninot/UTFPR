#include <stdio.h>

int main (void)
{
	int N, i=1, b, base;
	
	scanf("%d",&N);

	while(N > 0)
	{
		base = 2;
		b = N-1; 

		while(b > 0){ //porque o ^ não funfa
			base = base * 2;
			b--;
		}
		
		base--; //-1 ta aqui

		printf("Teste %d\n",i);
		printf("%d\n\n",base);
		i++;
		scanf("%d",&N);
	}

	return 0;
}
