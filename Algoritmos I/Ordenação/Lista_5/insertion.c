#include <stdio.h>
#include <stdlib.h>

void insertion(int *vet, int tam)
{
    int i, j, x;

    for(j=1; j<tam; j++)
    {
        x = vet[j];
        for(i=(j-1); i >= 0 && vet[i] > x; i--)
            vet[i+1] = vet[i];
        vet[i+1] = x;
    }
}

int main(void)
{
    int num[1000], i=0, j, cont=1;

    while(scanf("%d",&num[i]) == 1 && num[i] != EOF)
        i++;

    insertion(num,i);

    //printf("\n");
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
