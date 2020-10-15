#include <stdio.h>
#include <stdlib.h>
#define false 0;
#define true 1;

typedef struct no
{
	l_type elem;
	no *prox;
}

typedef struct lista
{
	no *inicio;
	int cont;
}lista;

void inicializa_lista(lista *L)
{
	L->inicio = NULL;
	L->cont = 0;
}

int insere_inicio(lista *L, l_type elem)
{
	no *novono = (no*)malloc(sizeof(no));
	
	if(novono == NULL)
		return false;
	novono->elem = elem;
	novono->prox = L->inicio;
	L->inicio = novono;
	L->cont++;
	return true;
}

l_type remove_inicio(lista *L)
{
	l_type ret = L->inicio->elem;
	no *arm = L->inicio;
	
	L->inicio = L->inicio->prox;
	free(arm);
	L->cont--;
	return ret;
}

int insere_fim(lista *L, l_type elem)
{
	no *tmp, *novono;
	
	novono = (no*)malloc(sizeof(no));  //ponteiro?
	if(novono == NULL)
		return false;
	
	novono->elem = elem;
	novono->prox = NULL;
	
	if(L->inicio == NULL)
		L->inicio = novono;
	else
	{
		tmp = L->inicio;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novono;
	}
	L->cont++;
	return true;
}

l_type remove_fim(lista *L)
{
	no *tmp = L->inicio, ant = L->inicio;  //ant certo?
	
	while(tmp->prox != NULL)
	{
		ant = tmp;
		tmp = tmp->prox;
	}
	
	l_type ret = tmp->elem;
	
	if(L->inicio == tmp)
		L->inicio = NULL;
	ant->prox = NULL;
	free(tmp);
	L->cont--;
	return ret;
}

void remove_no(lista *L, no *remover)
{
	if(remover != L->inicio)
	{
		no *tmp = L->inicio;
		
		while(tmp->prox != remover)
			tmp = tmp->prox;
		
		tmp->prox = remover->prox;
		free(remover);
		L->cont--;
	}
	else
		remove_inicio(L);
}

int busca(lista *L, l_type elem)
{
	no *tmp = L->inicio;
	int k = 1;
	
	while(tmp->elem != elem && tmp->prox != NULL)
	{
		tmp = tmp->prox;
		k++;
	}
	if(tmp->elem == elem)
		return k;
	else
		return -1;
}

int insere_ordenado(lista *L, l_type elem)
{
	if(L->inicio == NULL)
		return insere_inicio(L, elem);
		
	no *novo = (no*)malloc(sizeof(no));
	
	novono->elem = elem;
	
	no *atual, anterior = L->inicio;
	
	while(eh_menor(atual->elem,elem) == 1)
	{
		anterior = atual;
		atual = atual->prox;
	}
	
	novono->prox = atual;
	anterior->prox = novono;
}

//eh_maior retorna 1 se o primeiro > segundo
// 0 se forem iguais
// -1 se o segundo > primeiro
