#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int elem;
	struct no *ant, *prox;
}no;

typedef struct lista
{
	int cont;
	no *inicio;
}lista;

typedef struct parimpar
{
	struct no *par, *impar;
}parimpar;

void inicializa_lista(lista *L)
{
	L->inicio = NULL;
	L->cont = 0;
}

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
	
	return nl;	//sempre retorno o inicio?
}

no* insere_int_fim(no *L, int elem)
{
	no *novo = (no*)malloc(sizeof(no));	//aloco o novo no
	no *tmp;
	no *inicio = L;
	
	if(novo == NULL)			//se der shit
		return NULL;
		
	if(L == NULL)
	{
		L = novo;
		novo->elem = elem;
		novo->prox = NULL;
		novo->ant = NULL;
		
		return novo;		//retorno sempre o inicio
	}
	
	while(L->prox != NULL)		//andando pra encontrar o fim
		L = L->prox;
		
	L->prox = novo;		//porque o próximo é == NULL
	novo->elem = elem;
	novo->ant = L;
	novo->prox = NULL;
	
	return inicio;	//sempre retorno o inicio
}

parimpar* divide(no *inicio)
{
	no *par = NULL, *impar = NULL, *prox;
	
	while(inicio != NULL)
	{
		prox = inicio->prox;
		
		if(inicio->elem % 2 == 0)
			par = InsereNoFim(par,inicio);
		else
			impar = InsereNoFim(impar,inicio);
		
		inicio = prox;
	}
	
	parimpar *ret;
	ret = (parimpar*)malloc(sizeof(parimpar));
	ret->par = par;
	ret->impar = impar;
	
	return ret;
}

void imprimenos(no *no)
{
	while(no != NULL)
	{
		printf("%d ",no->elem);
		no = no->prox;
	}
	printf("\n");
}

void imprimelista(lista *L)
{
	imprimenos(L->inicio);
}

int main (void)
{
	lista *L;
	int N;
	
	L = (lista*)malloc(sizeof(lista));	//aloco na memória
	
	while(scanf("%d",&N) == 1 && N != 0)			//leio os valores
	{
		L->inicio = insere_int_fim(L->inicio,N);		//o nó tem que receber o nó
	}
	
	printf("Lista inicial:\n");
	imprimelista(L);
	
	struct parimpar *ret;
	
	ret = divide(L->inicio);
	
	printf("Lista Par:\n");
	imprimenos(ret->par);
	printf("Lista Impar:\n");
	imprimenos(ret->impar);
	
	return 0;
}
