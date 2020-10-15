#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//**********BUSCA BINÁRIA DO RIBAS************
int BB(int *vet, int e, int d, int x)      //e = esquerda; d = direita; x = valor a ser buscado
{
    if(e > d)
        return -1;

    int m = (e+d)/2;

    if(vet[m] == x)
        return m;
    if(vet[m] < x)
        return BB(vet,m+1,d,x);
    else
        return BB(vet,e,m-1,x);
}
int BuscaBinaria(int x, int *v, int tam)
{
    return BB(v,0,tam-1,x);
}

//*************BUSCA BINÁRIA DA LUCIENE*************** COMPLEXIDADE LOG N
int buscab(int *vet, int inicio, int fim, int chave)
{
    int meio;

    if(fim < inicio)
        printf("Elemento nao encontrado.\n");
    else
    {
        meio = (inicio+fim)/2;

        if(vet[meio] > chave)       //se o meio foi maior que o valor, ele vai pegar o lado esquerdo do vetor pra analisar
            return buscab(vet,inicio,meio-1,chave);
        else
        {
            if(vet[meio] < chave)   //se o meio foi menor que o valor, ele vai pegar o lado direito do vetor pra analisar
                return buscab(vet,meio+1,fim,chave);
            else
                return meio;
        }
    }
}

void ImprimeVet(int *vet, int tam)
{
    int i;

    for(i=0; i<tam; i++)
        printf("%d ",vet[i]);
    printf("\n");
}

void GeraVetorAleatorio(int *vet, int tam, int limInf, int limSup)
{
    srand(time(NULL));
    int i;

    for(i=0;i<tam;i++)
    {
        vet[i] = (rand() % (limSup - limInf) + limInf);
    }
}

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

int main(void)
{
    int tam=50, valor, posicao;
    int vet[tam];

    GeraVetorAleatorio(vet,tam,0,100);
    printf("Vetor gerado:\n");
    ImprimeVet(vet,tam);

    printf("Vetor ordenado:\n");
    MeuMergeSort(vet,tam);
    ImprimeVet(vet,tam);

    printf("Qual valor deseja buscar? ");
    scanf("%d",&valor);
    posicao = buscab(vet,0,tam,valor);
    //posicao = BuscaBinaria(valor,vet,100);
    printf("Este numero esta na posicao %d do vetor.\n",posicao);

    return 0;
}
