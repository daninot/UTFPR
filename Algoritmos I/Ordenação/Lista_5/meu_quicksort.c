#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int divide(int *vet, int esquerda, int direita)
{
    int i = esquerda, j;

    for(j=esquerda + 1; j<=direita; j++)
    {
        if(vet[j] < vet[esquerda]) //se o valor do vetor no �ndice j for menor que o valor do vetor no �ndice 'esquerda'
        {
            ++i; //primeiro soma o valor e depois "coloca" no i
            swap(&vet[i],&vet[j]);
        }
    }
    swap(&vet[esquerda],&vet[i]);

    return i;
}
void QuickSort(int *vet, int esquerda, int direita)
{
    int q;

    if(direita > esquerda)
    {
        q = divide(vet,esquerda,direita);
        QuickSort(vet,esquerda,q-1);
        QuickSort(vet,q+1,direita);
    }
}

int main(void)
{
    int num[100000], i=0, j, cont=1;

    while(scanf("%d",&num[i]) == 1 && num[i] != EOF)
        i++;

    QuickSort(num,0,i-1);

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
