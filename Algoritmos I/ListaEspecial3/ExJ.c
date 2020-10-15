#include <stdio.h>

typedef struct saldo
{
	int inicio, fim, soma;
}saldo;

void lerpartidas(int N, int *V)
{
	int i, X, Y;
	
	for(i=0; i<N; i++)
	{
		scanf("%d %d",&X,&Y);
		
		V[i] = X-Y;
	}
}

saldo mvapd(int inicio, int fim, int *dif) //dif é a diferença entre o número de gol marcados e número de gols levados
{
	saldo ret;
	ret.inicio = inicio + 1;
	
	int soma = dif[inicio], maiorsoma = soma;
	inicio++;
	
	while(soma >= 0 && inicio < fim)
	{
		soma = soma + dif[inicio];
		inicio++;
	}
	if(maiorsoma <= 0)
	{
		ret.soma = -1;
		return ret;
	}
	ret.soma = maiorsoma;
	
	return ret;
}

void imprimeresposta(int teste, saldo *melhor)
{
	printf("Teste %d\n",teste);
	if(melhor->soma <= 0)
	{
		printf("nenhum\n\n");
	}
	else
	{
		printf("%d %d\n\n",melhor->inicio,melhor->fim);
	}
}

int main (void)
{
	int N, i, teste=1, dif[10000]; 
	saldo melhor, encontrado;
	melhor.soma=-1;
	
	while(scanf("%d",&N) == 1 && N != 0)
	{
	        lerpartidas(N,dif);
	        
	        for(i=0;i<N;i++)
	        {
	        	encontrado = mvapd(i,N,dif); //melhor valor a partir de
	        	
	        	if(encontrado.soma > melhor.soma)
	        	{
	        		melhor = encontrado;
	        	}
	        }
	        imprimeresposta(teste++,&melhor);
	}
	
	return 0;
}
