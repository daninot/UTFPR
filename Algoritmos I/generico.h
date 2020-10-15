#ifndef __generico
#define __generico
#define MAXL 100
#define l_type int
#define false 0
#define true 1

typedef struct lista
{
	int inicio, fim, cont;
	l_type vet[MAXL];
}lista;

void inicializa_lista(lista *L);

int insere_fim(lista *L, l_type elem);

int insere_inicio(lista *L, l_type elem);

int empilha(lista *L, l_type elem);

int enfila(lista *L,l_type elem);

void inicializa_pilha(lista *L);

void inicializa_fila(lista *L);

l_type remove_inicio(lista *L);

l_type desenfila(lista *L);

l_type remove_fim(lista *L);

l_type desempilha(lista *L);

int insere_emk(lista *L, l_type elem, int k);

l_type remove_k(lista *L, int k);

int busca(lista *L, l_type elem);

void copia_lista(lista *L1, lista *L2);

void imprimelista(lista *L);

#endif
