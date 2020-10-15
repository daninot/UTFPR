#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int elem;
    struct no *prox, *ant;
}no;

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

no* insere_int_fim(no *L, int elem)
{
	no *novo = (no*)malloc(sizeof(no));	//aloco o novo no
	no *tmp;
	no *inicio = L;

	if(novo == NULL)			//se der shit
		return 0;

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

lista* remove_elem(int elem, lista *L)
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

int main (void)
{
    unsigned int N, ident, M, i, saiu, removi=0, j=0;

    lista FilaOrigi;
    lista *aux;
    inicializa_lista(&FilaOrigi);

    //leitura da fila inicial
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        scanf("%d",&ident);
        FilaOrigi.inicio = insere_int_fim(FilaOrigi.inicio,ident);
    }

    //leitura da fila dos que saem
    scanf("%d",&M);
    int sairam[M];
    for(i=0; i<M; i++)
        scanf("%d",&sairam[i]);

    saiu = sairam[j];
    while(removi < M)
    {
        aux = remove_elem(saiu,&FilaOrigi);
        j++;
        saiu = sairam[j];
        removi++;
    }
    imprime(FilaOrigi.inicio);

    return 0;
}
