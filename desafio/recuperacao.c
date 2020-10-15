#include <stdio.h>

int main (void)
{
    int n, j=1;

    while(scanf("%d",&n) == 1 && n > 0 && n <= 100)
    {
        int k, i, soma, t=0;
        //printf("n = %d\n",n);
        if(n == 1)
            printf("Instancia %d\n0\n\n",j++);
        else
        {
            i=1;
            soma=0;
            while(i <= n)
            {
                scanf("%d",&k);
                //printf("i = %d\tk = %d\tsoma = %d\n",i,k,soma);
                if(k > 0)
                {
                    if(soma == k)
                    {
                        printf("Instancia %d\n%d\n\n",j++,soma);
                        t++;
                    }
                    soma = soma + k;
                }
                i++;
            }
            if(t == 0)
                printf("Instancia %d\nnao achei\n\n",j++);
        }
    }
    return 0;
}
