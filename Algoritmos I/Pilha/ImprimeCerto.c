#include <stdio.h>
#include <stdlib.h>

#define MAXP 100
#define true 1
#define false 0
#define s_type char

typedef struct pilha
{
	s_type vet[MAXP];
	int cont;
}pilha;

void inicializa_pilha(pilha *p)
{
	p->cont=0;
}

int empilha(pilha *p, int elem) //passa como parâmetro o elemento que vc quer que seja empilhado
{
	if(p->cont >= MAXP)
	{
		return false;
	}
	p->vet[p->cont++] = elem; //p->vet[p->cont] = elem;
	return true;			//p->cont++;
}

int esta_vazia(pilha *p)
{
	if(p->cont == 0)
	{
		return true;
	}
	return false;
}

int desempilha(pilha *p)
{
	if(esta_vazia(p) == true)
	{
		return;
	}
	return(p->vet[--p->cont]);
}

int main (void)
{
	pilha p;
	pilha p2;
	int lido, N, i=0;
	
	scanf("%d",&N);
	
	inicializa_pilha(&p);
	inicializa_pilha(&p2);
	
	while(i < N && scanf("%d",&lido) == 1) 
	{
		empilha(&p,lido);
		i++;
	}
	while(!esta_vazia(&p))
	{
		empilha(&p2,desempilha(&p));
	}
	printf("%d",desempilha(&p2));
	while(!esta_vazia(&p2))
	{
		printf(" %d",desempilha(&p2));
	}
	printf("\n");	
	
	return 0;
}
