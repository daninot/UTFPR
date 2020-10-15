#include <stdio.h>
#include <stdlib.h>
#include "generico.h"

typedef struct no
{
	int elem;
	struct no *ant, *prox;
}no;

typedef struct parimpar
{
	struct no *par, *impar;
}parimpar;

no* InsereNoFim(no *l, no *add)	
{
	no *nl = l;
	
	if(l == NULL)
	{
		add->ant = NULL;
		add->prox = NULL;
		return add;
	}
	
	while(l->prox != NULL)
		l = l->prox;
	
	l->prox = add;
	add->ant = l;
	add->prox = NULL;
	
	return nl;	
}

parimpar* divide(no *listano)
{
	no *par = NULL, *impar = NULL, *prox;
	
	while(listano != NULL)
	{
		prox = listano->prox;
		
		if(listano->elem % 2 == 0)
			par = InsereNoFim(par,listano);
		else
			impar = InsereNoFim(impar,listano);
		
		listano = prox;
	}
	
	parimpar *ret;
	ret = (parimpar*)malloc(sizeof(parimpar));
	ret->par = par;
	ret->impar = impar;
	
	return ret;
}

void imprime(no *L)
{
	while(L != NULL)
	{
		printf("%d ",L->elem);
		L = L->prox;
	}
	printf("\n");
}

int main (void)
{
	lista *L;
	int N;
	
	L = (lista*)malloc(sizeof(lista));	//aloco na memória a minha lista
	
	inicializa_lista(L);
	
	while(N != 0)			//leio os valores
	{
		scanf("%d",&N);
		insere_fim(L,N);
	}
	
	printf("lista inicial:\n");
	imprimelista(L);
	
	struct parimpar *ret;
	
	ret = divide(L->listano);
	
	printf("\nLista Par:\n");
	imprime(ret->par);
	printf("Lista Impar:\n");
	imprime(ret->impar);
	
	return 0;
}
