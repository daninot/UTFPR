#include <stdio.h>

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
	p->cont--;
	return p->vet[p->cont];
}

/*s_type desempilha(pilha *p)
{
	if(esta_vazia(&p) == true)
	{
		return(p->vet[--p->cont];
	}
}*/
