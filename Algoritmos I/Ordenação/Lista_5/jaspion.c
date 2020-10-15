#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dicio
{
    char japones[81], ptbr[81];
}dicio;

void imprimedicio(dicio *palavras, int tam)
{
    int i;
	for(i=0; i<tam; i++)
    {
		printf("%s ",palavras[i].japones);
        printf("%s ",palavras[i].ptbr);
        printf("\n");
	}
	printf("\n");
}

dicio insere_palavra(char *japones, char *ptbr)
{
    dicio novapalavra;

    strcpy(novapalavra.japones,japones);
    strcpy(novapalavra.ptbr,ptbr);

    return novapalavra;
}

void troca(dicio *a,dicio *b)
{
    dicio aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
int divide(dicio *palavras, int esquerda, int direita)
{
    int i = esquerda, j, retorno;

    for(j=esquerda + 1; j<=direita; j++)
    {
        retorno = strcmp(palavras[j].japones,palavras[esquerda].japones);
        if(retorno < 0) //se o retorno for > 0 quer dizer que palavras[j] > palavras[esquerda]
        {
            ++i;
            troca(&palavras[i],&palavras[j]);
        }
    }
    troca(&palavras[esquerda],&palavras[i]);

    return i;
}
void QuickSort(dicio *palavras, int esquerda, int direita)
{
    int q;

    if(direita > esquerda)
    {
        q = divide(palavras,esquerda,direita);
        QuickSort(palavras,esquerda,q-1);
        QuickSort(palavras,q+1,direita);
    }
}

/*Recebe uma cadeia de caracteres e um array[low,high] de caracteres cujos elementos
estão na ordem do dicionário. A função devolve um índice de um elemento de array que
seja igual a entrada. Se tal índice não existe, a função devolve -1
Fonte: http://www.ime.usp.br/~pf/mac0122-2003/aulas/bin-search.html*/
int BBString(char *key, dicio *string, int esquerda, int direita)
{
    int m, cmp;

    if(esquerda > direita)
        return -1;
    m = (esquerda + direita)/2;
    cmp = strcmp(key,string[m].japones);
    if (cmp == 0)
        return m;
    if (cmp < 0)
        return BBString(key,string,esquerda,m-1);
    else
        return BBString(key,string,m+1,direita);
}

int main (void)
{
    int T, N, M, i, j=0;
    char japa[81], br[81], entrada[81], aux[81], k, tam, indice, algo;

    scanf("%d",&T);
    while(j < T)
    {
        scanf("%d %d ",&M,&N);      //espacinho depois pra ler o \n do fim
        dicio palavras[M];
        i=0;
        while(i < M)
        {
            gets(japa);
            //scanf("%c",&algo);      //pra ler o \n q ficou no fim
            gets(br);
            palavras[i] = insere_palavra(japa,br);
            i++;
        }
        tam = i;
        //imprimedicio(&palavras,i);
        QuickSort(palavras,0,tam-1);
        //imprimedicio(palavras,tam);
        i=0;
        while(i < N)
        {
            while(scanf(" %s%c",entrada,&algo) && algo != '\n')
            {
                if(algo == ' ')
                {
                    indice = BBString(entrada,palavras,0,tam);
                    if(indice == -1)
                        printf("%s ",entrada);
                    else
                        printf("%s ",palavras[indice].ptbr);
                }
            }
            if(algo == '\n')
            {
                indice = BBString(entrada,palavras,0,tam);
                if(indice == -1)
                    printf("%s\n",entrada);
                else
                    printf("%s\n",palavras[indice].ptbr);
            }
            i++;
            //printf("\n");
        }
        j++;
    }
}
