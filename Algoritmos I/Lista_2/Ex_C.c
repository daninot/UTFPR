#include <stdio.h>

int main (void)
{
	int h, m, s, hs, ms, soma;

	while(scanf("%d:%d:%d",&h,&m,&s) != EOF)
	{
		soma=0;
		ms = m * 60;
		hs = h * 3600;
		soma = hs + ms + s;
		s=0;
		s = 86400 - soma;
		printf("%d\n",s);	
	} 

	return 0;
}
