#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 10000

typedef struct no
{
    int amigo;
    no *prox;
}no;

typedef struct lista
{
	no *inicio;
	int cont;
}lista;

void inicializa_lista(lista *L){
	L->inicio=NULL;
    	L->cont=0;
}

void inicializa_fila(lista *L){
	L->inicio=1;
	L->cont=0;
}

int insere_fim(lista *L, l_type elem)
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

int insere_inicio(lista *L, l_type elem)
{
	if(L->cont > MAXL)
	{
		return false;
	}
	if(L->cont != 0) //pra não acontecer: L->inicio apontando pra um no final e o L->fim apontando pra um indice vazio no inicio (caso em que insiro o primeiro numero
	{
		L->inicio = (MAXL + (L->inicio) % MAXL);
	}
	L->vet[L->inicio] = elem;
	L->cont++;
	return true;
}

int enfila(lista *L,l_type elem)
{
	return insere_fim(L,elem);
}

l_type remove_inicio(lista *L) //tem que retornar um elemento do tipo l_type
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

l_type desenfila(lista *L)
{
	return remove_inicio(L);
}

l_type remove_fim(lista *L)
{
	l_type ret;
	ret = L->vet[L->fim];

	if(L->cont > 1) //mesma questão se tiver só um elemento
	{
		L->fim = (MAXL + L->fim - 1) % MAXL;
	}
	L->cont--;
	return ret;
}

int insere_emk(lista *L, l_type elem, int k)
{
	if(L->cont >= MAXL) //>= ?
	{
		return false;
	}

	lista pilha;
	inicializa_pilha(&pilha);
	int i;

	for(i=0; i<(k-1); i++) //a gente tem que abrir um buraco na nossa lista pra colocar o elemento q qro inserir
	{
		empilha(&pilha,remove_inicio(L));
	}

	insere_inicio(L,elem);

	for(i=0; i<(k-1); i++)
	{
		insere_inicio(L,desempilha(&pilha));
	}

	return true;
}

void imprimelista(lista *L)
{
	int i;

	for(i=inicio; i<=fim; i++)
		printf("%d ",L->vet[i]);
	printf("\n");
}

int insere_amigo(lista *L,int amigo) //insere no inicio
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

int main (void)
{
    int K, N, M, A, B, i, testemunha;
    lista pessoas[MAXL], verificacao;

    while(scanf("%d %d %d",&N,&K,&M) == 3 && N != 0 && K != 0 && M != 0)
    {
        for(i=1; i<N; i++) 
            inicializa_lista(&pessoa[i]);       //pessoa[i] é uma lista como outra qualquer
        inicializa_fila(&verificacao);		//fila verificacao é onde eu vou verificar as pessoas 
        int vet[N];				//vetor que sinaliza a quantidade de amigos
        memset(vet,0,N);

        for(i=1; i<=K; i++)                     //vou ler as pessoas que ficaram sabendo no primeiro dia
        {
            scanf("%d",&testemunha);
            vet[testemunha] = 1;
            enfila(&verificacao,testemunha);
        }
        for(i=1; i<=K; i++)
        	printf("%d\t",vet[i]);
        printf("\n");
        imprimelista(&verificacao);
        
        for(i=1; i<=M; i++)                     //agora vou ler as relações entre as pessoas
        {
            scanf("%d %d",&A,&B);
            insere_amigo(&pessoas[A],B);        //insiro o amigo no índice da pessoa
            insere_amigo(&pessoas[B],A);        //e vice-versa
        }
	printf("pessoas[A]\n");
	imprimelista(&pessoas[A]);
	printf("pessoas[B]\n");
	imprimelista(&pessoas[B]);
	
	
    }
    return 0;
}
