#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 10000
#define l_type int
#define true 1
#define false 0

typedef struct no
{
    int amigo;
    struct no *prox;
}no;

typedef struct lista
{
	no *inicio;
	int cont;
}lista;

typedef struct fila
{
    l_type vet[MAXL];
    int cont, inicio, fim;
}fila;

void inicializa_lista(lista *L){
	L->inicio=NULL;
    	L->cont=0;
}

void inicializa_fila(fila *L){
    L->inicio=1;
    L->fim=1;
	L->cont=0;
}

int insere_inicio(fila *L, l_type elem)
{
	if(L->cont > MAXL)
	{
		return false;
	}
	if(L->cont != 0) //pra não acontecer: L->inicio apontando pra um no final e o L->fim apontando pra um indice vazio no inicio (caso em que insiro o primeiro numero
	{
		L->inicio = (MAXL + L->inicio) % MAXL;
	}
	L->vet[L->inicio] = elem;
	L->cont++;
	return true;
}

int insere_fim(fila *L, l_type elem)
{
    if(L->cont > MAXL)
    {
        return false;
    }
    if(L->cont != 0) //pra eu não ter L->inicio apontando num indice vazio e o L->fim apontando pro valor (caso em que insiro o primeiro numero)
    {
        L->fim = (L->fim+1) % MAXL;
    }
    L->vet[L->fim] = elem; //certo?
    L->cont++;
    return true;
}

int enfila(fila *L,l_type elem)
{
	return insere_fim(L,elem);
}

l_type remove_inicio(fila *L) //tem que retornar um elemento do tipo l_type
{
	l_type ret;

	ret = L->vet[L->inicio];

	if(L->cont > 1)
	{
		L->inicio = (L->inicio + 1) % MAXL; //pra se ele estiver no último índice do vetor, ele continue no início do vetor
	}
	L->cont--;
	return ret;
}

l_type remove_no(lista *L)                  //remove o no do inicio
{
	l_type ret = L->inicio->amigo;
	no *arm = L->inicio;

	L->inicio = L->inicio->prox;
	free(arm);
	L->cont--;

	return ret;
}

l_type desenfila(fila *L)
{
	return remove_inicio(L);
}

void imprimefila(fila *L)
{
	int i;

	for(i=L->inicio; i<=L->fim; i++)
		printf("%d ",L->vet[i]);
	printf("\n");
}

void imprimelista(no *no)
{
	while(no != NULL)
	{
		printf("%d ",no->amigo);
		no = no->prox;
	}
	printf("\n");
}

int insere_amigo(lista *L, int amigo) //insere no inicio
{
    no *novoamigo = (no*)malloc(sizeof(no));
    if(novoamigo == NULL)
        return 0;
    novoamigo->amigo = amigo;
    novoamigo->prox = L->inicio;
    L->inicio = novoamigo;
    L->cont++;
    return 1;
}
int busca(fila *L, l_type elem)
{
	int i, k=1;
    i = L->inicio;

	while(k <= L->cont && L->vet[i] != elem)
	{
		i=(i+1) % MAXL;
		k++;
	}
	if(k > L->cont)
		return -1;
	return k;
}

int esta_vazia(fila *L)
{
	if(L->cont == 0)
		return 1;
	else
		return 0;
}

int main (void)
{
    int K, N, M, A, B, i, testemunha, elem, amigo, ordem, cont;
    lista pessoas[MAXL];
    fila verificacao;

    while(scanf("%d %d %d",&N,&K,&M) == 3 && N != 0 && K != 0 && M != 0)        //leio N K e M
    {
        for(i=1; i<=N; i++)
            inicializa_lista(&pessoas[i]);       //pessoa[i] é uma lista como outra qualquer
        inicializa_fila(&verificacao);          //fila verificacao serve para...
        int vet[N+1];                             //vetor que vai sinalizar a ordem de conhecimento das pessoas
        memset(vet,0,(N+1)*4);

        for(i=1; i<=K; i++)                     //vou ler as pessoas que ficaram sabendo no primeiro dia
        {
            scanf("%d",&testemunha);
            vet[testemunha] = 1;
            enfila(&verificacao,testemunha);    //enfilo na fila verificação as pessoas que já sabem
        }
        for(i=1; i<=M; i++)                     //agora vou ler as relações entre as pessoas
        {
            scanf("%d %d",&A,&B);
            insere_amigo(&pessoas[A],B);        //insiro o amigo no índice da pessoa
            insere_amigo(&pessoas[B],A);        //e vice-versa
        }

	      ordem = 1;
        while(esta_vazia(&verificacao) == 0)                  //enquanto a fila verificacao estiver vazia eu vou verificando
        {
            elem = desenfila(&verificacao);         //desenfilo o índice da lista que quero verificar
            while(pessoas[elem].cont != 0)
            {
                amigo = remove_no(&pessoas[elem]);      //removo o amigo do inicio desta lista

                if(vet[amigo] == 0)
                {
                    enfila(&verificacao,amigo);
                    vet[amigo] = vet[elem]+1;
                    if(ordem < vet[amigo])
                        ordem = vet[amigo];
                }
            }
        }
        cont=0;
        for(i=1; i<=N; i++)
        {
            if(vet[i] == ordem)
            {
            	if(cont == 0)
            	{
                	printf("%d",i);
                	cont++;
                }
                else
                	printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
