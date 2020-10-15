#include <stdio.h>

int puzzle(unsigned int N, int vezes)
{
	if(N == 1)
		return (vezes);
	if(N % 2 == 0)
		return puzzle((N/2),vezes+1);
		
	return puzzle(((3*N)+1),vezes+1);
}

int main (void)
{
	int i, j, aux, k, maior, troquei, qtd;
	
	while(scanf("%d %d",&i,&j) != EOF)	
	{
		troquei=0;
		maior=0;
		if(i > j)
		{
			aux = i;
			i = j;
			j = aux;
			troquei++;
		}
	
		for(k=i; k<=j; k++)
		{
			qtd = puzzle((unsigned int)k,1);
		
			if(qtd > maior)
				maior = qtd;
		}
	
		if(troquei > 0)
		{
			printf("%d %d %d\n",j,i,maior);
		}
		else
			printf("%d %d %d\n",i,j,maior);
	}
		
	return 0;
}
