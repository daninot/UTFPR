#include <stdio.h>

int main (void)
{
	int D, d1, d2, d3;
	
	scanf("%d",&D);
	scanf("%d %d %d",&d1,&d2,&d3);
	
	if((d1 < D) || (d2 < D) || (d3 < D))
	{
		printf("N\n");
	}
	else
	{
		printf("S\n");
	}
	
	return 0;
}
