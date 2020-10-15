#include <stdio.h>
#include <stdlib.h>

#define f_type int
#define s_type int
#define MAXF 100
#define MAXP 100
#define true 1
#define false 0

typedef struct pilha
{
	s_type vet[MAXP];
	int cont;
}pilha;

void inicializa_pilha(pilha *p)
{
	p->cont=0;
}

int empilha(pilha *p, int elem) //passa como parâmetro o elemento que vc quer que seja empilhado
{
	if(p->cont >= MAXP)
	{
		return false;
	}
	p->vet[p->cont++] = elem; //p->vet[p->cont] = elem;
	return true;			//p->cont++;
}

s_type desempilha(pilha *p)
{
	if(esta_vaziapilha(&p) == true)
	{
		return;
	}
	return(p->vet[--p->cont]);
}

int esta_vaziapilha(pilha *p)
{
	if(p->cont == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
typedef struct fila
{
	f_type vet[MAXF];
	int cont, inicio, fim;
}fila;

void inicializa_fila(fila *f)
{
	f->cont=0;
	f->inicio=0;
	f->fim=0;
}

int esta_vaziafila(fila *f)
{
	if(f->cont==0)
	{
		return true;
	}
	return false;
}

int enfila(fila *f, f_type elem)
{
	if(f->cont > MAXF)
	{
		return false;
	}
	
	f->vet[f->fim] = elem;
	f->cont++;
	f->fim = ((f->fim+1) % MAXF);
	return true;
	
}

f_type desenfila(fila *f)
{
	f_type ret;
	
	ret = f->vet[f->inicio];
	f->inicio = ((f->inicio+1) % MAXF);
	f->inicio++;
	f->cont--;
	return ret;
}

void impcont(fila *f)		//forma recursiva (jurandi q fez)
{
	int n;
	
	if(esta_vaziafila(f))
	{
		return;
	}
	n = desenfila(f);
	impcont(f);
	printf("%d\t",n);
}

void imprimecont(fila *f)
{
	pilha p;
	
	inicializa_pilha(&p);
	
	while(esta_vaziafila(f) == false)
	{
		empilha(&p,desenfila(f));
	}
	while(esta_vaziapilha(&p) == false)
	{
		printf("%d ",desempilha(&p));
	}
	printf("\n");
}

int main (void)
{
	fila f;
	int num;
	
	inicializa_fila(&f);
	
	while(scanf("%d ",&num) == 1)
	{
		enfila(&f,num);
	}
	
	//impcont(&f);
	imprimecont(&f);
	
	return 0;
}
