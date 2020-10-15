void inicializa_lista(lista *L)
{
	L->inicio = NULL;
	L->cont = 0;
}

no* InsereNoFim(no *l, no *add)	
{
	no *nl = l;
	
	if(l == NULL)
	{
		add->ant = NULL;
		add->prox = NULL;
		return add;
	}
	
	while(l->prox != NULL)
		l = l->prox;
	
	l->prox = add;
	add->ant = l;
	add->prox = NULL;
	
	return nl;	//sempre retorno o inicio?
}

no* insere_int_fim(no *L, int elem)
{
	no *novo = (no*)malloc(sizeof(no));	//aloco o novo no
	no *tmp;
	no *inicio = L;
	
	if(novo == NULL)			//se der shit
		return NULL;
		
	if(L == NULL)
	{
		L = novo;
		novo->elem = elem;
		novo->prox = NULL;
		novo->ant = NULL;
		
		return novo;
	}
	
	while(L->prox != NULL)		//andando pra encontrar o fim
		L = L->prox;
		
	L->prox = novo;		//porque o próximo é == NULL
	novo->elem = elem;
	novo->ant = L;
	novo->prox = NULL;
	
	return inicio;
}

/*no* insere_int_fim(no *L, int elem)
{
	no *novo = (no*)malloc(sizeof(no));	//aloco o novo no
	no *tmp;
	
	if(novo == NULL)			//se der shit
		return NULL;
		
	if(L->inicio == NULL)
	{
		L->inicio = novo;
		novo->elem = elem;
		novo->prox = NULL;
		novo->ant = NULL;
		
		L->cont++;
		
		return novo;
	}
	
	tmp->prox = novo;
	novo->elem = elem;
	novo->ant = tmp;
	novo->prox = NULL;
	
	L->cont++;
	tpm = novo;

	return true;
}*/

parimpar* divide(no *inicio)
{
	no *par = NULL, *impar = NULL, *prox;
	
	while(inicio != NULL)
	{
		prox = inicio->prox;
		
		if(inicio->elem % 2 == 0)
			par = InsereNoFim(par,inicio);
		else
			impar = InsereNoFim(impar,inicio);
		
		listano = prox;
	}
	
	parimpar *ret;
	ret = (parimpar*)malloc(sizeof(parimpar));
	ret->par = par;
	ret->impar = impar;
	
	return ret;
}

void imprimenos(no *no)
{
	while(no != NULL)
	{
		printf("%d ",no->elem);
		no = no->prox;
	}
	printf("\n");
}

void imprimelista(lista *L)
{
	imprimenos(L->inicio);
}

