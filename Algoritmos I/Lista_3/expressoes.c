#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXP 100000
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

int empilha(pilha *p, int elem) 
{
	if(p->cont >= MAXP)
	{
		return 0;
	}
	p->vet[p->cont++] = elem; 
	return 1;			
}

s_type desempilha(pilha *p)
{
	if(p->cont == 0)
	{
		return 0;
	}
	return(p->vet[--p->cont]);
}

int esta_vazia(pilha *p)
{
	if(p->cont == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main (void)
{
	pilha p;
	int T, i, tam, j=0, nope;
	char A[100001], aux;
	
	scanf("%d",&T);
	
	while(j<T && scanf("%s",A) == 1)
	{
		inicializa_pilha(&p);
		tam = strlen(A);
		nope=0;
		
		if(tam % 2 == 0)
		{
			for(i=0;i<tam;i++)
			{
				if(A[i] == '(' || A[i] == '[' || A[i] == '{')
				{
					empilha(&p,A[i]);
				}
				else if(A[i] == ')')
				{
					if(desempilha(&p) != '(')
						nope++;
				}
				else if(A[i] == ']')
				{
					if(desempilha(&p) != '[')
						nope++;
				}
				else if(A[i] == '}')
				{
					if(desempilha(&p) != '{')
						nope++;
				}
			}
		}
		else
			nope++;	
		if(nope == 0)
			printf("S\n");
		else
			printf("N\n");	
		j++;
	}
	return 0;	
}
