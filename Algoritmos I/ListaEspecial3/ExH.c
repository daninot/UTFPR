#include <stdio.h>

int main(void)
{
	short int N, V, T, i;
	int D=0;
	
	scanf("%hd",&N);
	
	for(i=0; i<N; i++)
	{
		scanf("%hd %hd",&T,&V);
		
		D = D + (T * V);
	}
	printf("%d\n",D);

	return 0;
}
