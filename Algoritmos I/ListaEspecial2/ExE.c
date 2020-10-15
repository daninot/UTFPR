#include <stdio.h>

int main (void)
{
	int f, o, l, vet_qtds[3], i, menor;
	
	scanf("%d %d %d",&f,&o,&l);
		
	if(f < 2 || o < 3 || l < 5)
	{
		printf("0\n");
	}
	else
	{
		vet_qtds[0] = f / 2;
		vet_qtds[1] = o / 3;
		vet_qtds[2] = l / 5;

		menor = vet_qtds[0];
		
		for(i=0; i<3; i++)
		{
			if(vet_qtds[i] < menor)
			{
				menor = vet_qtds[i];
			}
		}
		printf("%d\n",menor);
	}

	return 0;
}
