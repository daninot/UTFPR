#include <stdio.h>
#include <stdlib.h>

typedef struct Orks
{
    int X;
    int Y;
    struct Orks *prox;
}Orks;

typedef struct lista_de_Orks
{
    Orks *inicio;
    int cont;
}lista_de_Orks;

void inicializa_lista(lista_de_Orks *L)
{
	L->inicio=NULL;
    L->cont=0;
}

Orks* inserenofim(Orks *o, lista_de_Orks *L, int x, int y)
{
    Orks *novo = (Orks*)malloc(sizeof(Orks));

    if(novo == NULL)
        return NULL;
    if(o == NULL)
    {
        novo->X = x;
        novo->Y = y;
        novo->prox = NULL;
        L->cont++;
        L->inicio = novo;
        return novo;
    }
    novo->X = x;
    novo->Y = y;
    o->prox = novo;
    novo->prox = NULL;
    L->cont++;

    return novo;                   //retorno o último ork
}

int tem_ork_nesta_linha(lista_de_Orks *L)
{
    if(L->inicio == NULL)
        return 0;
    else
        return 1;
}

/*int tem_ork_nesta_coluna(lista_de_Orks *L, int N, int xK, int yK)
{
    int i=0;

    while(i < N)
    {
        if(L[i]->inicio != NULL)
        {
            i = N;
            return 1;
        }
        else
            i++;
    }
}*/é

int main ()
{
    lista_de_Orks lista[99];
    int N, M, C, i, j, xK, yK, orks, novoX, novoY;
    Orks *ultimo_ork;

    while(scanf("%d %d %d",&N,&M,&C) == 3 && N != 0 && M != 0 && C != 0)
    {
        for(i=0; i<N; i++)
            inicializa_lista(&lista[i]);

        char battle[100][100];
        Orks=0;

        //leio o campo de batalha
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                scanf(" %c",&battle[i][j]);

                if(battle[i][j] == 'L')
                {
                    xL = j;
                    yL = i;
                }
                else if(battle[i][j] == 'O')
                {
                    Orks++;
                    if(lista[i].cont == 0)
                        ultimo_ork = inserenofim(&lista[i].inicio,j,i);
                    else
                        ultimo_ork = inserenofim(ultimo_ork,j,i);
                }
            }
        }
        //imprimo o campo de batalha
        printf("\n");
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                printf("%c",battle[i][j]);
            }
            printf("\n");
        }
        printf("qtd Orks = %d\n",Orks);

        //vejo se há orks na posição atual do kégolas
        if(tem_ork_nesta_linha(lista[yK],xK,yK) == 1)
        {

        }

        //agora vou ler os comandos e processar
        for(i=0; i<C; i++)
        {
            scanf("%d %d",&novoX,novoY);
            while(novoX > (xK+4) || novoX < (xK-4) || novoY > (yK+4) || novoY < (yK-4))
                scanf("%d %d",&novoX,novoY);


        }


    }

    return 0;
}
