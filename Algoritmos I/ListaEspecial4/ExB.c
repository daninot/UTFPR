#include <stdio.h>		//não deu certo

int main (void)
{
	int N;
	scanf("%d",&N);
	
	int notas[101], i, j, k=0, repetidas[N], nota;
	
	for(i=0;i<N;i++)
		scanf("%d",&notas[i]);

	for(i=0;i<N;i++)
	{	
		for(j=i+1; j<N; j++)
		{
			if(notas[i] == notas[j])
			{
				repetidas[k] = notas[j];
				nota = repetidas[k];
			
				if(repetidas[k] > repetidas[k+1])
					nota = repetidas[k];
		
				k++;
			}
		}
	}
	printf("%d\n",nota);
		
	return 0;
}
