#include <stdio.h>		//deu certo
#include <stdlib.h>
#include <string.h>

int main(void)
{
    	int N, K, i, menor;
    
    	scanf("%d %d",&N,&K);

    	int tipinhos[N], tipos[K+1];
   
    	memset(tipos,0,sizeof(tipos));
    
    	for(i=0; i<N; i++)
    	{
        	scanf("%d",&tipinhos[i]);
        	tipos[tipinhos[i]]++;
    	}
    
    	menor = tipos[1];
    
    	for(i=2; i<=K; i++)
    	{
        	if(tipos[i] < menor)
            		menor = tipos[i];
   	}
    	printf("%d\n",menor);
    	return 0;
}
