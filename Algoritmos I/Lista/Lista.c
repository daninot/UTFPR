#include <stdio.h>
#include <stdlib.h>

#define MAXL 100
#define true 1
#define false 0

typedef struct lista
{
	l_type vet[MAXL];
	int cont;
	int inicio, fim;
}lista;

void inicializa_lista(lista *L)
{
	inicializa_fila(&L);
}

int insere_fim(lista *L, l_type elem)
{
	return enfila(L,elem);
}

int insere_inicio(lista *L, l_type elem)
{
	if(L->cont > MAXL)
	{
		return false;
	}
	L->inicio = (MAXL + (L->inicio) % MAXL);
	L->vet[L->inicio] = elem;
	L->cont++;
	return true;
}

int insere_emk(lista *L, l_type elem, int k)
{
	pilha aux;
	int i;
	
	inicializa_pilha(&aux);
	
	if(L->cont > MAXL)
	{
		return false;
	}
	
	for(i=0; i<(k-1); i++)
	{
		empilha(&aux,remove_inicio(L));
	}
	
	insere_inicio(L,elem);
	
	for(i=0; i<(k-1); i++)
	{
		insere_inicio(L,desempilha(&aux));
	}
	
	L->cont++;
	
	return true;
}

l_type remove_k(lista *L, int k)
{
	l_type ret;
	pilha aux;
	int i;
	
	inicializa_pilha(&aux);
	
	for(i=0; i<(k-1); i++)
	{
		empilha(&aux,remove_inicio(L));
	}
	
	ret = remove_inicio(L);
	
	for(i=0; i<(k-1); i++)
	{
		insere_inicio(L,desempilha(&aux));
	}
	
	L->cont--;
	
	return ret;
}

int busca(lista *L, l_type elem)
{
	int i, k=1;
	i=L->inicio;
	
	while(k <= L->cont && L->vet[i] != elem)
	{
		i=(i+1) % MAXL;
		k++;
	}
	if(k > L->cont)
	{
		return -1;
	}
	
	return k;
}
