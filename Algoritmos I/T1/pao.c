#include <stdio.h>
#include <stdlib.h>

int bbtamanhodopao(int *sand, int direita, int esquerda, int teste)
{
    int metade;

    while(esquerda <= direita)
    {
        metade = (esquerda + direita) / 2; //aqui determino minha metade pra logo descobrir em quais dos lados vou ficar

        if(sand[metade] == teste)
            return(metade);

        if(sand[metade] < teste) //se o valor do vetor na metade for menor que o Valor, ent�o ele est� na metade da
            esquerda = metade + 1; //atualizo a metade da esquerda

        else
            direita = metade - 1; //atualizo a metade da direita
    }
    return(-1);
}

int alimentaquantos(int *sand, int tam, int tam_sand)   //vetor sanduiches, o tamanho do vetor, e o tam de cada sanduíche
{
    int qtd=0, i;

    for(i=0;i<tam;i++)
        qtd = qtd + (sand[i]/tam_sand);
    return qtd;
}

int main (void)
{
    int N, K, i, soma=0, npessoas=0, tam, ideal, teste, metade, direita, esquerda;

    scanf("%d",&N);                       //leio o número de pessoas
    scanf("%d",&K);                       //leio a quantidade de tipos de sanduíches
    int sanduiches[K];
    for(i=0;i<K;i++)
    {
        scanf("%d",&sanduiches[i]);        //leio a metragem de cada tipo de pao e coloco no meu vetor sanduiches
        soma = soma + sanduiches[i];
    }

    tam = soma/N;
    npessoas = alimentaquantos(sanduiches,K,tam);
    direita=tam;
    esquerda=0;
    while((direita - esquerda) > 1)
    {
        metade = (direita+esquerda)/2;
        npessoas = alimentaquantos(sanduiches,K,metade);

        if(npessoas > N || npessoas == N)
            esquerda = metade;
        else if(npessoas < N)
            direita = metade;
    }
    printf("%d\n",esquerda);

    return 0;
}
