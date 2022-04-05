#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct shows
{
    char cidade[27];
    struct shows *prox;
}shows;

typedef struct lista_shows
{
    shows *inicio;
    int qtd;
}lista_shows;

void inicializa_lista(lista_shows *L)
{
    L->inicio = NULL;
    L->qtd = 0;
}

shows* insere_cidade_nofim(shows *c, char *str, lista_shows *L)     //sempre passo como parâmetro a última (que vai ser a penúltima)
{
    shows *novac = (shows*)malloc(sizeof(shows));

    if(novac == NULL)
        return NULL;
    if(c == NULL)
    {
        strcpy(novac->cidade,str);
        novac->prox = NULL;
        L->qtd++;
        L->inicio = novac;
        return novac;               //como novac é a única cidade na lista, ela é a última
    }
    strcpy(novac->cidade,str);
    c->prox = novac;
    novac->prox = NULL;
    L->qtd++;

    return novac;                   //retorno a última
}

void imprime(shows *s)
{
	while(s != NULL)
	{
		printf("%s\n",s->cidade);
		s = s->prox;
	}
}

void consertalista(shows *c, shows *ultima)
{
    shows *aux = c->prox;
    shows *tmp;
    int i;
    while(c->prox != NULL)
    {
        i=0;
        while(c->cidade[i] != '\0')
            i++;
        i--;
        if(aux->cidade[0] == (c->cidade[i] - 32))
        {
            tmp = aux;
            c->prox = aux->prox;
            aux = aux->prox;
            ultima->prox = tmp;
            tmp->prox = NULL;
            ultima = tmp;
        }
        c = aux;
        aux = aux->prox;
    }
}

int main (void)
{
    lista_shows lista;
    inicializa_lista(&lista);
    char aux[27];
    shows *ultima_cidade;

    while(scanf(" %s",aux) != EOF)
    {
        if(lista.qtd == 0)
        {
            ultima_cidade = insere_cidade_nofim(lista.inicio,aux,&lista);
        }
        else
        {
            ultima_cidade = insere_cidade_nofim(ultima_cidade,aux,&lista);
        }
    }
    consertalista(lista.inicio,ultima_cidade);
    imprime(lista.inicio);
    return 0;
}
