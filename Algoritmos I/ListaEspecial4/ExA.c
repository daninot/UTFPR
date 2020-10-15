#include <stdio.h>
#define MAX_ALUNOS 1000

int main(void)
{
	int i, N, turma=1, maior_nota, j;
  	
  	struct
  	{
    		int codigo, media;
  	} alunos[MAX_ALUNOS];
  
  	scanf("%d",&N);
  	
  	while (N > 0)
    	{
		maior_nota = 0;
		j=0;
	     	for(i=0; i<N; i++)
	     	{
		 	scanf("%d %d",&alunos[i].codigo,&alunos[i].media);
		 	
	 		if(alunos[i].media > maior_nota)
	 		{
	 			maior_nota = alunos[i].media;
	 		}
		}
      		printf("Turma %d\n",turma++);
	      	for(i=0; i<N; i++)
	      	{	      		
	      		if(alunos[i].media == maior_nota)
	      		{
	      			if(j > 0)
	      			{
	      				printf(" %d",alunos[i].codigo);
	      			}
	      			else
	      			{
	      				printf("%d",alunos[i].codigo);
	      			}
	      			j++;
	      		}
		}
		printf("\n\n");

	      	scanf("%d",&N);
    	}
    	
  	return 0;
}
