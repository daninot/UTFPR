#include <stdio.h>
#include <stdlib.h>

#define MAXP 100
#define true 1
#define false 0
#define s_type char

typedef struct pilha
{
	s_type vet[MAXP];	//s_type?
	int cont;
}pilha;

void inicializa_pilha(pilha *p)
{
	p->cont=0;
}

int empilha(pilha *p, int elem) //passa como parâmetro o elemento que vc quer que seja empilhado
{
	if(p->cont >= MAXP)	//só vou empilhar se ainda tem espaço no vetor
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
	p->cont--;
	return (p->vet[p->cont]); 	//return(p->vet[--p->cont]);
}

int main(void)
{
	pilha p; 
	int lido, n, i=0;
	
	scanf("%d",&n);
	
	inicializa_pilha(&p);
	
	while(i < n && scanf("%d",&lido) == 1)
	{
		empilha(&p,lido);
		i++;
	}
	
	printf("%d",desempilha(&p));
	
	while(!esta_vazia(&p))
	{
		printf(" %d",desempilha(&p));
	}
	printf("\n");
	
	return 0;
}
