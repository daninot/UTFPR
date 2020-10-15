#include <stdio.h>
#include <stdlib.h>
#define MAXL 50000
#define false 0
#define true 1
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
		return false;
	}
	if(L->cont != 0) //pra eu não ter L->inicio apontando num indice vazio e o L->fim apontando pro valor (caso em que insiro o primeiro numero)
	{
		L->fim = (L->fim+1) % MAXL;
	}
	L->vet[L->fim] = elem;
	L->cont++;
	return true;
}

int insere_inicio(lista *L, l_type elem)
{
	if(L->cont > MAXL)
	{
		return false;
	}
	if(L->cont != 0) //pra não acontecer: L->inicio apontando pra um no final e o L->fim apontando pra um indice vazio no inicio (caso em que insiro o primeiro numero
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

l_type remove_inicio(lista *L) //tem que retornar um elemento do tipo l_type
{
	l_type ret;

	ret = L->vet[L->inicio];

	if(L->cont > 1)
	{
		L->inicio = (L->inicio + 1) % MAXL; //pra se ele estiver no último índice do vetor, ele continue no início do vetor
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

	if(L->cont > 1) //mesma questão se tiver só um elemento
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

void remove_k(lista *L, int k)
{
	lista pilha;
	inicializa_pilha(&pilha);
	int i;

	for(i=0; i<k; i++)
		empilha(&pilha,remove_inicio(L));
	remove_inicio(L);
	for(i=0; i<k; i++)
		insere_inicio(L,desempilha(&pilha));
}

int esta_vazia(lista *L)
{
	if(L->cont == 0)
	{
		return 1;
	}
	return 0;
}

int busca(lista *L, l_type elem)
{
	int i, k=0;

	i = L->inicio; //i=0

	while(k < L->cont && L->vet[i] != elem)
	{
		i=(i+1) % MAXL;
		k++;
	}

	return k;
}

/*int BuscaRBinaria(lista *L, int elem)
{
    int metade=0, esquerda=(L->inicio), direita=(L->fim);

    while(esquerda <= direita)
    {
        metade = (esquerda + direita) / 2; //aqui determino minha metade pra logo descobrir em quais dos lados vou ficar

        if(L->vet[metade] == elem)
        {
            return(metade);
        }
        if(L->vet[metade] < elem) //se o valor do vetor na metade for menor que o Valor, então ele está na metade da
        {
            esquerda = metade + 1; //atualizo a metade da esquerda
        }
        else
        {
            direita = metade - 1; //atualizo a metade da direita
        }
    }
    return(-1);
}*/

void imprimelista(lista *L)
{
	int i;
	for(i=(L->inicio); i<=(L->fim); i++)
		printf("%d ",L->vet[i]);
	printf("\n");
}

int main (void)
{
    int N, ID, M, i, dif, j;
    lista Fila;
    lista aux;
    inicializa_lista(&Fila);

    //leitura da fila inicial
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        scanf("%d",&ID);
        enfila(&Fila,ID);       //enfilo na fila Fila todo mundo que chegou
    }

    //leitura da fila dos que saíram
    scanf("%d",&M);
    int sairam[M];
    for(i=0; i<M; i++)
        scanf("%d",&sairam[i]);

	//processamento
	j=0;
    while(j < M)
    {
        remove_k(&Fila,busca(&Fila,sairam[j]));

		inicializa_lista(&aux);
		while(esta_vazia(&Fila) != 1)
			enfila(&aux,desenfila(&Fila));
		inicializa_lista(&Fila);
		while(esta_vazia(&aux) != 1)
			enfila(&Fila,desenfila(&aux));

        j++;
    }
	imprimelista(&Fila);

    return 0;
}
