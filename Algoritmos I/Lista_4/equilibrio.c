#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXP 1001
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
	if(esta_vazia(p) == 1)
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
	int i, nope;
	char string[MAXP];
	
	fgets(string,MAXP,stdin);
	while(string[0] != '.')
	{
		inicializa_pilha(&p);
		nope=0;
		i=0;
		
		while(string[i] != '.' && string[i+1] != '\0')
		{
			if(string[i] == '(' || string[i] == '[')
			{
				empilha(&p,string[i]);
			}
			else if(string[i] == ')')
			{
				if(desempilha(&p) != '(')
					nope++;
			}
			else if(string[i] == ']')
			{
				if(desempilha(&p) != '[')
					nope++;
			}
			i++;
		}
		
		if(esta_vazia(&p) == 1)
		{
			if(nope == 0)
				printf("yes\n");
			else
				printf("no\n");
		}
		else
			printf("no\n");
		
		fgets(string,MAXP,stdin);
	}
	return 0;	
}
