#include <stdio.h>

int main (void)
{
	float A, G, Ra, Rg;
	
	scanf("%f %f %f %f",&A,&G,&Ra,&Rg);
	
	if((A / Ra) < (G / Rg))
	{
		printf("A\n");
	}
	else
	{
		printf("G\n");
	}
	
	return 0;
}
