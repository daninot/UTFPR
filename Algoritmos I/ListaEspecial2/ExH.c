#include <stdio.h>

int main (void)
{
	int vet[5], contC=0, contD=0, i, j;
	
	scanf("%d %d %d %d %d",&vet[0],&vet[1],&vet[2],&vet[3],&vet[4]);
	
	for(i=0;i<5;i++)
	{
		
		for(j=i+1;j<5;j++)
		{
			if(vet[i] > vet[j])
			{
				contC++;
			}
			else if(vet[i] < vet[j])
			{
				contD++;
			}
		}
	}
	
	if(contC == 0)
	{
		printf("C\n");
	}
	else if(contD == 0)
	{
		printf("D\n");
	}
	else
	{
		printf("N\n");
	}

	return 0;
}
