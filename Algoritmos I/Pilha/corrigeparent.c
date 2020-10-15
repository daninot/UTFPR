#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXP 100
#define true 1
#define false 0
#define s_type char

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
	if(esta_vazia(&p) == true)
	{
		return;
	}
	return(p->vet[--p->cont]);
}

int esta_vazia(pilha *p)
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

int main (void)
{
	pilha p;
	int i, tam;
	char s[101];
	
	scanf("%s",s);
	inicializa_pilha(&p);
	tam = strlen(s);
	
	for(i=0;i<tam;i++)
	{
		if(s[i] == '(' || s[i] == '[')
		{
			empilha(&p,s[i]);
		}
		else if(s[i] == ')')
		{
			if(desempilha(&p) != '(')
			{
				printf("you shall not pass.\n");
				return;
			}
		}
		else if(s[i] == ']')
		{
			if(desempilha(&p) != ']')
			{
				printf("you shall not pass.\n");
				return;
			}
		}
	}
	if(esta_vazia(&p) == true)
	{
		printf("Ok, legal.\n");
	}
	else
	{
		printf("you shall not pass.\n");
	}
	return 0;
	
	
}
