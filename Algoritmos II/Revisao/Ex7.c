#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXP 1000
#define s_type char

typedef struct pilha
{
    s_type vet[MAXP];
    int cont;
}pilha;

void inicializa_pilha(pilha *p){
    p->cont=0;
}

int empilha(pilha *p, int elem)
{
    if(p->cont >= MAXP)
        return 0;

    p->vet[p->cont++] = elem;
    return 1;
}

int esta_vazia(pilha *p)
{
    if(p->cont == 0)
        return 1;

    return 0;
}

int desempilha(pilha *p)
{
    if(esta_vazia(p) == 1)
        return 1;

    p->cont--;
    return (p->vet[p->cont]);
}

int main(void)
{
    pilha p;
    inicializa_pilha(&p);
    char str[MAXP];
    int i=0;

    gets(str);
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != '.')
            empilha(&p,str[i]);
        else
        {
            while(esta_vazia(&p) != 1)
                printf("%c",desempilha(&p));
            if(str[i] != '.')
                printf(" ");
        }
        i++;
    }
    printf(".\n");

    return 0;
}
