#include <stdio.h>		//deu certo

int main(void)
{
    	int N;
    	scanf("%d",&N);
    
   	int notas_alunos[N], nota[101], i, mais_repetida, imprime;
    
    	for(i=0; i<101; i++) 
		nota[i] = 0;
    
	for(i=0; i<N; i++)
	{
		scanf("%d",&notas_alunos[i]);
		nota[notas_alunos[i]]++;
	}
    
    	mais_repetida = nota[0]; //que é 0;
    
    	for(i=1; i<101 ;i++)
    	{
        	if(nota[i] >= mais_repetida)
        	{
        		mais_repetida = nota[i];
        		imprime = i;
        	}
    	}
    	printf("%d\n",imprime);
    	
    return 0;
}
