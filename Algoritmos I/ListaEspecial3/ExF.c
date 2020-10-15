#include <stdio.h>

int main (void)
{
	int R, aldo, beto, a, b, i, j=1;
	
	while(scanf("%d",&R) == 1 && R != 0)
	{
		a=0;
		b=0;
		for(i=0; i<R; i++)
		{
			scanf("%d %d",&aldo,&beto);
			a = a + aldo;
			b = b + beto;
		}
		printf("Teste %d\n",j);
		if(a > b)
		{
			printf("Aldo\n\n");
		}
		else
		{
			printf("Beto\n\n");
		}
		j++;
	}

	return 0;
}
