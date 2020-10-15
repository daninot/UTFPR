#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int elem;
	struct no *prox, *ant;
}no;

typedef struct lista
{
	int cont;
	no *inicio;
}lista;

void inicializa_lista(lista *L)
{
	L->inicio = NULL;
	L->cont = 0;
}

void adiciona(no *quem, lista *lista) // qual das listas, a par ou a impar
{
	quem->ant = NULL;
	
	quem->prox = lista->inicio; 

	if(lista->inicio != NULL)
		lista->inicio->ant = quem;
		
	lista->inicio = quem;
}

lista* divide(no *ptr)
{
	lista *L = (lista*)malloc(2*sizeof(lista));
	no *aux;
	
	inicializa_lista(&L[0]);
	inicializa_lista(&L[1]);
	
	while(ptr != NULL)
	{
		aux = ptr->prox;
		
		if(ptr->elem % 2 == 0)
			adiciona(ptr,&L[1]);
		else
			adiciona(ptr,&L[0]);
		ptr = aux;
	}
	return L;
}

int insere_int_inicio(lista *L, int elem)
{
	no *novo = (no*)malloc(sizeof(novo));
	
	if(novo == NULL)
		return 0;
		
	novo->elem = elem;
	novo->prox = L->inicio;
	
	if(L->inicio != NULL)
		L->inicio->ant = novo;
		
	novo->ant = NULL;
	L->inicio = novo;
	L->cont++;
	
	return 1;
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
	struct lista *ler;
	ler = (lista*)malloc(sizeof(lista));
	inicializa_lista(ler);
	
	int N;
	while(scanf("%d",&N) == 1 && N != 0)
		insere_int_inicio(ler,N);
	
	printf("Lista inicial:\n");
	imprimelista(ler);
	
	struct lista *ret;
	ret = (lista*)malloc(sizeof(lista));
	ret = divide(ler->inicio);
	
	printf("Lista par:\n");
	imprimelista(&ret[1]);
	printf("Lista impar:\n");
	imprimelista(&ret[0]);
	
	return 0;
}
