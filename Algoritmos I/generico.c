#define MAXL 100
#define l_type int
#define false 0
#define true 1

typedef struct lista
{
	int inicio, fim, cont;
	l_type vet[MAXL];
}lista;

void inicializa_lista(lista *L)
{
	L->inicio=0;
	L->fim=0;
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

int empilha(lista *L, l_type elem)
{
	return insere_fim(L,elem);
}

int enfila(lista *L,l_type elem)
{
	return insere_fim(L,elem);
}

void inicializa_pilha(lista *L)
{
	inicializa_lista(L);
}

void inicializa_fila(lista *L)
{
	inicializa_lista(L);
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

l_type desempilha(lista *L)
{
	return remove_fim(L);
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

l_type remove_k(lista *L, int k)
{
	l_type ret;
	
	lista pilha;
	int i;
	
	inicializa_pilha(&L);
	
	for(i=0; i<(k-1); i++)
	{
		empilha(&pilha,remove_inicio(L));
	}
	
	ret = remove_inicio(L); //ao invés de inserir na k-ésima posição, removo
	
	for(i=0; i<(k-1); i++)
	{
		insere_inicio(L,desempilha(&pilha));
	}
	
	return ret;
}

int busca(lista *L, l_type elem)
{
	int i, k=1;
	
	i = L->inicio;
	
	while(k <= L->cont && L->vet[i] != elem)
	{
		i=(i+1) % MAXL;
		k++;
	}
	if(k > L->cont)
	{
		return -1;
	}
	
	return k;
}

void copia_lista(lista *L1, lista *L2)
{
	inicializa_lista(L1);
	
	lista fila;
	inicializa_fila(&fila);
	
	int i;
	l_type aux;
	
	while(esta_vazia(L1) != false)
	{
		enfila(&fila,remove_fim(L1));
	}
	while(esta_vazia(&fila) != false)
	{
		aux = desenfila(&fila);
		insere_inicio(L1,aux);
		insere_inicio(L2,aux);
	}
}

