#include <stdio.h>
#define MAXL 50
#define l_type int

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
		return 0;
	}
	if(L->cont != 0) 
	{
		L->fim = (L->fim+1) % MAXL;
	}
	L->vet[L->fim] = elem; 
	L->cont++;
	return 1;
}
int enfila(lista *L,l_type elem)
{
	return insere_fim(L,elem);
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
int sobrou_um(lista *L)
{
	if(L->cont == 1)
		return 1;
	return 0;
}
int sobrou_dois(lista *L)
{
	if(L->cont == 2)
		return 1;
	return 0;
}
int main (void)
{
	int N, i;
	lista cartas;
	
	while(scanf("%d",&N) == 1 && N != 0)
	{ 
		inicializa_fila(&cartas);
		for(i=0;i<N;i++) 					
		{
			enfila(&cartas,i+1);
		}
		if(N > 1)
		{	
			printf("Discarded cards: ");
			while(sobrou_um(&cartas) == 0)
			{
				if(sobrou_dois(&cartas) == 0)
					printf("%d, ",cartas.vet[cartas.inicio]);
				else
					printf("%d\n",cartas.vet[cartas.inicio]);
				desenfila(&cartas); 				
				enfila(&cartas,desenfila(&cartas));				
			}
		}	
		else
			printf("Discarded cards:\n");
			
		if(sobrou_um(&cartas) == 1)
				printf("Remaining card: %d\n",cartas.vet[cartas.inicio]);
	}
	return 0;
}

