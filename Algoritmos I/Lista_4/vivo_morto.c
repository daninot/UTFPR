#include <stdio.h>
#define MAXL 100
#define l_type int
#define false 0
#define true 1

typedef struct lista
{
	int inicio, fim, cont;
	l_type vet[MAXL];
}lista;

void inicializa_lista(lista *L)
{
	L->inicio=0;
	L->fim=0;
	L->cont=0;
}

int insere_fim(lista *L, l_type elem)
{
	if(L->cont > MAXL)
	{
		return false;
	}
	if(L->cont != 0)
	{
		L->fim = (L->fim+1) % MAXL;
	}
	L->vet[L->fim] = elem; //certo?
	L->cont++;
	return true;
}

int insere_inicio(lista *L, l_type elem)
{
	if(L->cont > MAXL)
	{
		return false;
	}
	if(L->cont != 0)
	{	
		L->inicio = (MAXL + (L->inicio-1)) % MAXL;
	}
	L->vet[L->inicio] = elem;
	L->cont++;
	return true;
}

int empilha(lista *L, l_type elem)
{
	return insere_fim(L,elem);
}

int enfila(lista *L,l_type elem)
{
	return insere_fim(L,elem);
}

void inicializa_pilha(lista *L)
{
	inicializa_lista(L);
}

void inicializa_fila(lista *L)
{
	inicializa_lista(L);
}

l_type remove_inicio(lista *L) 
{
	l_type ret;
	
	ret = L->vet[L->inicio];
	
	if(L->cont > 1)
	{	
		L->inicio = (L->inicio + 1) % MAXL; 
	}
	L->cont--;
	return ret;
}

l_type desenfila(lista *L)
{
	return remove_inicio(L);
}

l_type remove_fim(lista *L)
{
	l_type ret;
	ret = L->vet[L->fim];
	
	if(L->cont > 1) 
	{
		L->fim = (MAXL + L->fim - 1) % MAXL;
	}
	L->cont--;
	return ret;
}

l_type desempilha(lista *L)
{
	return remove_fim(L);
}

int insere_emk(lista *L, l_type elem, int k)
{
	if(L->cont >= MAXL) 
	{
		return false;
	}
	
	lista pilha;
	inicializa_pilha(&pilha);
	int i;
	
	for(i=0; i<(k-1); i++) 
	{
		empilha(&pilha,remove_inicio(L));
	}
	
	insere_inicio(L,elem);
	
	for(i=0; i<(k-1); i++)
	{
		insere_inicio(L,desempilha(&pilha));
	}

	return true;
}

l_type remove_k(lista *L, int k)
{
	l_type ret;
	
	lista pilha;
	int i;
	
	inicializa_pilha(&pilha);
	
	for(i=0; i<(k-1); i++)
	{
		empilha(&pilha,remove_inicio(L));
	}
	
	ret = remove_inicio(L); 
	
	for(i=0; i<(k-1); i++)
	{
		insere_inicio(L,desempilha(&pilha));
	}
	
	return ret;
}

int busca(lista *L, l_type elem)
{
	int i, k=1;
	
	i = L->inicio;
	
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

int main (void)
{
	int P, R, N, J, i, j, participante, teste=1, acoes, k;
	lista ordem;
	
	while(scanf("%d %d",&P,&R) == 2 && (P != 0 && R != 0))
	{
		inicializa_fila(&ordem);
		
		for(i=0; i<P; i++) 					
		{
			scanf("%d",&participante);
			enfila(&ordem,participante);
		}
		
		for(i=0; i<R; i++)
		{	
			scanf("%d %d",&N,&J);			
			k=0;
			for(j=0; j<N; j++)
			{
				scanf("%d",&acoes);
				k++;
				if(acoes != J)
				{
					remove_k(&ordem,k);
					k--;
				}
			}
		}
		
		printf("Teste %d\n%d\n\n",teste++,ordem.vet[ordem.inicio]);
	}
	return 0;
}
