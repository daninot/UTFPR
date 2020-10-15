#include <stdio.h>

int main (void)
{
	int qtd, VT=0;
	
	scanf("%d",&qtd);
	
	if(qtd <= 10)
	{
		printf("7\n");
	}
	else
	{
		
		if((qtd > 10) && (qtd <= 30))
		{
			VT = (qtd - 10) + 7;
		}
		else if((qtd > 30) && (qtd <= 100))
		{
			VT = 27 + ((qtd - 30) * 2);
		}
		else if(qtd > 100)
		{
			VT = 167 + ((qtd - 100) * 5);
		}
		
		printf("%d\n",VT);
	}
	
	return 0;
}
