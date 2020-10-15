#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int elem;
    struct no *prox;
}no;

typedef struct lista
{
    no *inicio;
}lista;

void inicializa_lista(lista *L)
{
	L->inicio = NULL;
}

int insere_fim(lista *L, int elem)
{
	no *tmp, *novono = (no*)malloc(sizeof(no));

	if(novono == NULL)
		return 0;

	novono->elem = elem;
	novono->prox = NULL;

	if(L->inicio == NULL)
		L->inicio = novono;

	else{
		tmp = L->inicio;

		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novono;
	}

	return 1;
}

int remove_inicio(lista *L)
{
	int ret = L->inicio->elem;
	no *arm = L->inicio;

	L->inicio = L->inicio->prox;
	free(arm);

	return ret;
}

no* busca(lista *L, int elem)
{
	no *tmp = L->inicio;

	while(tmp->elem != elem && tmp->prox != NULL)
		tmp = tmp->prox;

	if(tmp->elem == elem)
		return (tmp);
	else
		return NULL;
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
	}
	else
		remove_inicio(L);
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
        insere_fim(&FilaOrigi,ident);
    }

    //leitura da fila dos que saem
    scanf("%d",&M);
    int sairam[M];
    for(i=0; i<M; i++)
        scanf("%d",&sairam[i]);

    saiu = sairam[j];
    while(removi < M)
    {
        remove_no(&FilaOrigi,busca(&FilaOrigi,saiu));
        j++;
        saiu = sairam[j];
        removi++;
    }
    imprime(FilaOrigi.inicio);

    return 0;
}
