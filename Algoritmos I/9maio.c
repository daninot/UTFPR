typedef struct no
{
	int elem;
	struct no *ant, *prox;
}no;

typedef struct parimpar
{
	struct no *par, *impar;
}parimpar;

no* InsereNoFim(no *l, no* add)		//ponteiro do tipo no
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
	
	return nl;	
}

no* divide(no *inicio)
{
	no *par = NULL, *impar = NULL, *prox;
	
	while(inicio != NULL)
	{
		prox = inicio->prox;
		
		if(inicio->elem % 2 == 0)
			par = InsereNoFim(par,inicio);
		else
			impar = InsereNoFim(impar,inicio);
		
		inicio = prox;
	}
	
	parimpar ret;
	ret.par = par;
	ret.impar = impar;
	
	return ret;
}
