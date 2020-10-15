struct no
{
	char tipo; //T, D
	int dist;
	struct no *prox, *desvio;
}

int eh_possivel(struct no *ptr1, struct no *ptr2)
{
	struct no *atual;
	
	fila f; //poderia ser pilha
	inicializa_fila(&f);
	
	atual = ptr1;
	
	while(atual != ptr2)
	{
		enfila(&f,atual->prox);
		
		if(atual->tipo == 'D')
			enfila(&f,atual->desvio);
		
		atual = desenfila(&f);
	}
}




