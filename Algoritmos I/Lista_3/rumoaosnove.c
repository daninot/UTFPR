#include <stdio.h>
#include <string.h>
#define TAM 1001

int grau9(int num)
{
	int soma=0;
	
	if(num == 9)
	{
		return 1;
	}
	if(num % 9 == 0) 
	{
		while(num > 0) //vou somar os algarismos
		{
			soma = soma + (num % 10);
			num = num / 10;
		}
		return(1 + grau9(soma)); 	
	}
	else
	{
		return 0;
	}
}

int main (void)
{
	int i, resposta, j, soma, tam;
	char N[TAM];
	
	while(scanf("%s",N) == 1 && N[0] != 48) //o 0 é 48
	{
		tam = strlen(N);
		i=0;
		soma=0;
		
		while(i < tam)
		{
			N[i] = N[i] - 48;
			soma = soma + N[i];
			i++;
		}
	
		resposta = grau9(soma);
		
		if(resposta == 0)
		{
			for(j=0; j<tam; j++)
			{
				printf("%d",N[j]);
			}
			printf(" is not a multiple of 9.\n");
		}
		else
		{
			for(j=0; j<tam; j++)
			{
				printf("%d",N[j]);
			}
			printf(" is a multiple of 9 and has 9-degree %d.\n",resposta);
		}
	}
	
	return 0;
}
