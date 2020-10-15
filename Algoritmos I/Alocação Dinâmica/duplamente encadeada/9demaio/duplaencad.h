#ifndef __duplaencad
#define __duplaencad
#define MAXL 100
#define l_type int
#define false 0
#define true 1

typedef struct no
{
	int elem;
	struct no *ant, *prox;
}no;

typedef struct lista
{
	int cont;
	no *inicio;
}lista;

typedef struct parimpar
{
	struct no *par, *impar;
}parimpar;

void inicializa_lista(lista *L);

no* InsereNoFim(no *l, no *add);

no* insere_int_fim(no *L, int elem);

parimpar* divide(no *listano);

void imprimenos(no *no);

void imprimelista(lista *L);

#endif
