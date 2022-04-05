#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ImprimeVet(int *vet, int tam)
{
    int i;

    for(i=0; i<tam; i++)
        printf("%d ",vet[i]);
    printf("\n");
}

//função cria um vetor com números aleatórios
void GeraVetorAleatorio(int *vet, int tam, int limInf, int limSup)
{
    srand(time(NULL));
    int i;

    for(i=0;i<tam;i++)
    {
        vet[i] = (rand() % (limSup - limInf) + limInf);
    }
}

//################# B U B B L E  S O R T ###################
void BubbleSort(int *vet, int tam)
{
    int i, j, aux;

    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(vet[i] > vet[j])
            {
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }
}

//################# Q U I C K  S O R T ####################
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

//################### M E R G E  S O R T #####################
void merge(int *vet, int tam)
{
    int metade, i, j, k, *w;

    w = (int*)malloc(tam*sizeof(int)); //malloc cria o vetor do tamanho tam
    metade = tam/2;
    i = 0;
    j = metade;
    k = 0;
    while(i < metade && j < tam)
    {
        if (vet[i] <= vet[j])
            w[k] = vet[i++];
        else
            w[k] = vet[j++];
        ++k;
    }
    if(i == metade)
    {
        while (j < tam)
            w[k++] = vet[j++];
    }
    else
    {
        while(i < metade)
            w[k++] = vet[i++];
    }
    for (i=0; i<tam;i++)
        vet[i] = w[i];

    free(w);
}
void MeuMergeSort(int *vet, int tam)
{
    int metade;
    if(tam > 1)
    {
        metade = (tam/2);
        MeuMergeSort(vet,metade);
        MeuMergeSort(vet + metade,tam - metade);
        merge(vet,tam);
    }
}


int main (void)
{
    clock_t t;
    int tamanho, valor_maximo, i;

    printf("Qual o tamanho do vetor? ");
    scanf("%d",&tamanho);
    printf("Qual o limite maximo dos valores? ");
    scanf("%d",&valor_maximo);

    int *vetor = (int*)malloc(tamanho * sizeof(int));
    int *vetor2 = (int*)malloc(tamanho * sizeof(int));
    int *vetor3 = (int*)malloc(tamanho * sizeof(int));

    GeraVetorAleatorio(vetor,tamanho,0,valor_maximo);
    for(i=0; i<tamanho; i++)
    {
        vetor2[i] = vetor[i];
        vetor3[i] = vetor[i];
    }

    //printf("Vetor gerado:\n");
    //ImprimeVet(vetor,tamanho);

    t = clock();
    BubbleSort(vetor,tamanho);
    t = clock() - t;
    printf("A ordenacao do vetor de %d valores com Bubble Sort levou %.4f segundos.\n",tamanho,((float)t)/CLOCKS_PER_SEC);
    //ImprimeVet(vetor,tamanho);

    t = clock();
    QuickSort(vetor2,0,tamanho-1);
    t = clock() - t;
    printf("A ordenacao do vetor de %d valores com Quick Sort levou %.4f segundos.\n",tamanho,((float)t)/CLOCKS_PER_SEC);
    //ImprimeVet(vetor2,tamanho);

    t = clock();
    MeuMergeSort(vetor3,tamanho);
    t = clock() - t;
    printf("A ordenacao do vetor de %d valores com Merge Sort levou %.4f segundos.\n",tamanho,((float)t)/CLOCKS_PER_SEC);
    //ImprimeVet(vetor3,tamanho);

    return 0;
}
