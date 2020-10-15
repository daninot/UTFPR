#include <stdio.h>
#include <stdlib.h>

void troca(int *a,int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
void selection(int *v, int tam)
{
    int i, j, min;

    for(i=0; i<(tam-1); i++)
    {
        min = i;
        for(j=(i+1); j<tam; j++)
        {
            if(v[j] < v[min])
                min = j;
        }
        troca(&v[i],&v[min]);
    }
}

int main(void)
{
    int num[1000], i=0, j, cont=1;

    while(scanf("%d",&num[i]) == 1 && num[i] != EOF)
        i++;

    selection(num,i);

    for(j=0; j<i; j++)
    {
        if(cont == i)
            printf("%d\n",num[j]);
        else
            printf("%d ",num[j]);
        cont++;
    }
    return 0;
}
