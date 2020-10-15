#include <stdio.h>
#include <stdlib.h>

#define MAXP 10000
#define s_type char

typedef struct pilha
{
    s_type vet[MAXP];
    int cont;
}pilha;

void inicializa_pilha(pilha *p)
{
    p->cont = 0;
}

int empilha(pilha *p, s_type elem) //passa como parâmetro o elemento que vc quer que seja empilhado
{
    if(p->cont >= MAXP)   //só vou empilhar se ainda tem espaço no vetor
        return 0;

    p->vet[p->cont] = elem;
    p->cont++;
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
        return 0;

    p->cont--;
    return (p->vet[p->cont]);
}

int main(void)
{
    pilha p;
    inicializa_pilha(&p);

    int i=0;
    char str;

    printf("Digite um numero inteiro: ");
    while(scanf("%c",&str) == 1 && str != '\n')
    {
        empilha(&p,str);
    }

    printf("Seu numero invertido e: ");
    while(esta_vazia(&p) == 0)
    {
        printf("%c",desempilha(&p));
    }
    printf("\n");

    return 0;
}
