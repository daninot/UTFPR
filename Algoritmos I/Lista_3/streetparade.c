#include <stdio.h>
#include <stdlib.h>

#define MAXP 1000
#define s_type int

typedef struct pilha
{
	s_type vet[MAXP];
	int cont;
}pilha;

void inicializa_pilha(pilha *p)
{
	p->cont=0;
}

int empilha(pilha *p, int elem) 
{
	if(p->cont >= MAXP)
	{
		return 0;
	}
	p->vet[p->cont] = elem;
	p->cont++;
	return 1;			
}

s_type desempilha(pilha *p)
{
	if(esta_vazia(p) == 1)
	{
		return -1;
	}
	p->cont--;
	return(p->vet[p->cont]);
}

s_type ultimoelem(pilha *p)
{
	if(esta_vazia(p) == 1)
	{
		return -1;
	}
	return (p->vet[p->cont-1]);
}

int esta_vazia(pilha *p)
{
	if(p->cont == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main (void)
{
	int N, parade[MAXP], j, i, k, nao, carro_atual, qtd;
	pilha aux;
		
	while(scanf("%d",&qtd) == 1 && qtd != 0)
	{
		inicializa_pilha(&aux); j=0; nao=0; carro_atual=1; k=0; 
		
		while(j < qtd && scanf("%d",&N) == 1)
		{	
			while(ultimoelem(&aux) == carro_atual)
			{
				parade[k++] = desempilha(&aux);
				carro_atual++;
			}
			if(N == carro_atual)
			{
				parade[k++] = N;
				carro_atual++;
			}
			else
			{
				empilha(&aux,N);
			}
			j++;
		}
		
		while(k < j)
			parade[k++] = desempilha(&aux);
	
		for(j=0; j<k; j++)
		{		
			for(i=j+1; i<k; i++)
			{
				if(parade[i] < parade[j])
					nao++;
			}
		}
		if(nao == 0) 
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
