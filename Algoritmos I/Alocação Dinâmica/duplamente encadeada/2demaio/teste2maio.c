#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define l_type int

typedef struct no no;
struct no
{
	l_type elem;
	no *prox;
	no *ant;
};

typedef struct lista
{
	no *inicio;
	int cont;
}lista;

void inicializa_lista(lista *L)
{
	L->cont = 0;
	L->inicio = NULL;
}

int insere_inicio(lista *L, l_type elem)
{
	no *novo = (no*)malloc(sizeof(no));
	
	if(novo == NULL)
		return false;
	
	novo->elem = elem;
	
	novo->prox = L->inicio;
	
	if(L->inicio != NULL)
		L->inicio->ant = novo;
	
	novo->ant = NULL;
	L->inicio = novo;
	L->cont++;
	return true;
}

int INSEREAPOS(no* anterior, l_type elem)
{
	no *novo = (no*)malloc(sizeof(no));
	
	if(novo == NULL)
		return false;
		
	novo->elem = elem;
	novo->prox = anterior->prox;
	
	if(anterior->prox != NULL)
		anterior->prox->ant = novo;
		
	novo->ant = anterior;
	anterior->prox = novo;
	
	return true;
}

l_type REMOVE(no *remover)
{
	if(remover->ant != NULL)
		remover->ant->prox = remover->prox;
	
	if(remover->prox != NULL)
		remover->prox->ant = remover->ant;
	
	l_type ret = remover->elem;
	free(remover);
	return ret;
}

l_type remover(lista *L, no *remover)
{
	l_type ret;
	L->cont--;
	ret = REMOVE(remover);
	
	if(L->cont == 0)
		L->inicio = NULL;
	
	return ret;
}

l_type removertodos(lista *L, no *remover)
{
	int aux = remover->elem;
	l_type ret;
	no* tmp = L->inicio;
	
	while(tmp != NULL)
	{
		if(tmp->elem == aux)
		{
			L->cont--;
			ret = REMOVE(remover);
	
			if(L->cont == 0)
				L->inicio = NULL;
		}
		tmp = tmp->prox;
	}
	return ret;
}

lista* remove_elem(l_type elem, lista *L)
{
	lista *lista = L;
	
	no *tmp = lista->inicio;
	no *aux;
	
	while(tmp->elem != elem && tmp != NULL)
		tmp = tmp->prox;
		
	if(tmp->elem == elem)
	{
		if(tmp->ant == NULL)
		{
			aux = tmp;
			lista->inicio = tmp->prox;
			tmp = lista->inicio;
			tmp->ant = NULL;
			//lista->inicio->ant = NULL;
			free(aux);
		}
		else if(tmp->prox == NULL)
		{
			aux = tmp;
			tmp->ant->prox = NULL;
			free(aux);
		}
		else
		{
			aux = tmp;
			tmp->ant->prox = tmp->prox;
			tmp->prox->ant = tmp->ant;
			free(aux);
		}
	}
	return lista;
}

/*lista* removertodos2(lista *L, l_type elem)
{
	lista *ll = L;
	no* tmp = L->inicio;
	
	while(tmp != NULL)
	{
		if(tmp->elem == elem)
		{
			ll = remove_elem(elem,ll);
		}
		tmp = tmp->prox;
	}
	return ll;
}*/

void troca2(no *ptr1, no *ptr2)
{
	no *aux = ptr1->prox, *aux2 = ptr2->ant;
	
	ptr1->prox = ptr2->prox;
	ptr2->prox->ant = ptr1;
	ptr2->prox = aux;
	aux->ant = ptr2;
	ptr2->ant = ptr1->ant;
	ptr1->ant->prox = ptr2;
	aux2->prox = ptr1;
	ptr1->ant = aux2;
}

void imprime(no *no)	//função recursiva para imprimir
{
	if(no != NULL)
	{
		printf("%d ",no->elem);
		imprime(no->prox);
	}
	else
		printf("\n");
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

no* busca_endereco(lista *L, l_type elem)
{
	no *tmp = L->inicio;
		
	while(tmp->elem != elem && tmp->prox != NULL)
		tmp = tmp->prox;
	
	if(tmp->elem == elem)
		return(tmp);
	else
		return NULL;
}

int main(void)
{
	lista *L = (lista*)malloc(sizeof(lista));  //declaração e alocação na memória
	inicializa_lista(L);
	
	l_type elem; 
	
	while(scanf("%d",&elem) == 1 && elem != EOF)	//vou ler os valores e inserir sempre no início da lista
	{							
		insere_inicio(L,elem);		//note que a forma como foi inserida a lista parece uma pilha
	}
	printf("Lista inserida:\n");
	imprime(L->inicio);			
	
	//quero remover um número da lista
	l_type rem;	
	lista *ret;
	/*do
	{
		printf("Qual deseja remover?\n");
		scanf("%d",&rem);
		ret = remove_elem(rem,L);
		printf("Sua lista ficou assim:\n");
		imprime(L->inicio);
	}while(rem != EOF);*/
	
	//trocar dois elementos na minha lista
	l_type t1,t2;
	printf("Quais elementos deseja trocar?\n");
	scanf("%d %d",&t1,&t2);
	//troca2(busca_endereco(L,t1),busca_endereco(L,t2));
	imprime(busca_endereco(L,t1));
	imprime(busca_endereco(L,t2));
	printf("Sua lista ficou assim:\n");
	imprime(L->inicio);
	
	return 0;
}
