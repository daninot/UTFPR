#include <stdio.h>
#include <stdlib.h>

char* retorna_caractere(char c)
{
	char *p;
	
	p = malloc(sizeof(c)*2);	//aloco um tamanho 2 vezes maior 
	
	p[0] = c;
	p[1] = '\0';
	
	return p;
}

int main ()
{
	char c, *p;
	
	scanf("%c",&c);
	
	p = retorna_caractere(c);
	
	printf("string: %s\n",p);
	printf("pos memoria: %p\n",p);
	
	printf("bytes int: %d\n",sizeof(int));
	printf("bytes ponteiro int: %d\n",sizeof(int*));
	printf("bytes ponteiro p: %d\n",sizeof(p));
	printf("bytes valor apontado por p: %d\n",sizeof(*p));
	
	return 0;
}
