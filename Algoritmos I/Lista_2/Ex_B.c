#include <stdio.h>

int main (void)
{
	int resp, i, qtd_s, qtd_t=0;
	char str[4];

	while(scanf("%s", str) != EOF)
	{
		qtd_s=0;
		
		if(str[0] == 's')
		{
			qtd_s++;
		}

		for(i=1; i<10; i++)
		{
			scanf("%s", str);

			if(str[0] == 's')
			{
				qtd_s++;
			}
		}
		if(qtd_s >= 2)
		{
			qtd_t++;
		}
	}
	
	printf("%d\n",qtd_t);

	return 0;
}
