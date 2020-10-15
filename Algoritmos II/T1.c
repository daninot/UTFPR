#include <stdio.h>
#include <stdlib.h>
#define Vertice int
#define Aresta int
#define true 1
#define false 0

//lista de adjacência de cada vértice;
typedef struct arestas
{
    Aresta aresta;             //representa o vértice de entrada
    struct arestas *prox, *ant;
}arestas;

//lista dos vértices
typedef struct vertices
{
    Vertice vert;
    arestas *inicio;        //início da lista de adjacência de cada vértice
    struct vertices *prox, *ant;
}vertices;

typedef struct grafo
{
    vertices *inicio;       //início da lista dos vértices
    int qtd_vertices;
    int qtd_arestas;
}grafo;

void inicializa_vertices(vertices *V)
{
    V->inicio = NULL;
}

void inicializa_grafo(grafo *G)
{
    G->inicio = NULL;
    G->qtd_arestas = 0;
    G->qtd_vertices = 0;
}

//insere um vértice no início da lista (passa como parâmetro sempre o início)
int Insere_Vertice_inicio(grafo *G, Vertice V)   //retorno sempre o inicio da lista de vertices
{
    vertices *novoV = (vertices*)malloc(sizeof(vertices));

    if(novoV == NULL)
        return false;
    if(G->inicio == NULL)
    {
        novoV->vert = V;
        novoV->prox = NULL;
        G->inicio = novoV;
        G->qtd_vertices++;
        return true;
    }
    novoV->vert = V;
    novoV->prox = G->inicio;
    G->inicio = novoV;
    G->qtd_vertices++;
    return true;
}

//insere um vértice no fim da lista(passa como parâmetro sempre o vértice final)
vertices* Insere_Vertice_fim(grafo *G, Vertice V, vertices *ultimo)
{
    vertices *novoV = (vertices*)malloc(sizeof(vertices));

    if(novoV == NULL)
        return NULL;
    if(ultimo == NULL)  //se eu entrar com o início do grafo e não houver nenhum vértice ainda
    {
        novoV->vert = V;
        novoV->prox = NULL;
        novoV->ant = NULL;
        G->inicio = novoV;
        G->qtd_vertices++;
    }
    novoV->vert = V;
    novoV->prox = NULL;
    ultimo->prox = novoV;
    novoV->ant = ultimo;
    G->qtd_vertices++;
    return novoV;
}

//remove um vértice do fim da lista(passa como parâmetro o último velho e retorna o último novo)
vertices* Remove_Vertice_fim(grafo *G, vertices *ultimo)
{
    if(ultimo == NULL)          //caso ele seja sacana e me passe uma lista vazia
        return NULL;
    else if(ultimo->ant == NULL)     //caso só tenha um vértice na lista
    {
        free(ultimo);
        return NULL;            //esvaziou a lista
    }
    vertices *aux = ultimo->ant;       //o aux é o penúltimo
    aux->prox = NULL;
    free(ultimo);
    return aux;                        //agr o aux é o último
}



//insere uma aresta (um vértice de entrada) no fim da lista de adjacência (leque de saída)
arestas* Insere_Aresta_fim(grafo *G, vertices *V, Aresta A, arestas *ultima)
{
    arestas *novaA = (arestas*)malloc(sizeof(arestas));

    if(novaA == NULL)
        return NULL;
    if(ultima == NULL)  //se eu entrar com o início da lista de adjacência e não houver nenhuma aresta
    {
        novaA->aresta = A;
        novaA->prox = NULL;
        novaA->ant = NULL;
        V->inicio = novaA;
        G->qtd_arestas++;
    }
    novaA->aresta = A;
    novaA->prox = NULL;
    ultima->prox = novaA;
    novaA->ant = ultima;
    G->qtd_arestas++;
    return novaA;           //retorna sempre a última aresta (o último vértice vizinho)
}

//imprime a lista de adjacências (leque de saída)
void VerArestas(arestas *A) //passa como parâmetro a primeira aresta da lista
{
    while(A != NULL)
    {
        printf("-> %d   ");
        A = A->prox;
    }
    printf("\n");
}

//imprime o grafo; passa como parâmetro o primeiro vértice da lista
void VerGrafo(grafo *G)
{
    while(V != NULL)
    {
        printf("-----\n");
        printf(" %d ");
        VerArestas(G->inicio->inicio);
    }
    printf("\n");
    printf("Este grafo possui %d vértices e %d arestas.\n",G->qtd_vertices,G->qtd_arestas);
}

int main(void)
{
    grafo Grafo;
    inicializa_grafo(&Grafo);
    char acao, remover, inserir;
    Vertice v, a;
    vertices *ultimo_vt;
    arestas *ultima_a;

    printf("Olá. O que deseja fazer?\n");
    do
    {
        printf("IV ou iv - para inserir vértice.\n");
        printf("RV ou rv - para remover vértice.\n");
        printf("IA ou ia - para inserir aresta.\n");
        printf("RA ou ra - para remover aresta.\n");
        printf("VG ou vg - para ver o grafo.\n");
        printf("S - para sair.\n");
        scanf(" %s",acao);

        //escolheu inserir um vértice
        if(acao == 'IV' || acao == 'iv')
        {
            do{
                printf("Para inserir no fim digite F.\n");
                printf("Para inserir no inicio digite I.\n");
                //printf("Para inserir ordenado, digite O.\n")
                scanf(" %s",inserir);

                if(inserir == 'F')
                {
                    printf("Digite o numero do vertice: ");
                    scanf("%d",&v);
                    if(Grafo.inicio == NULL)    //caso ainda não tenha sido inserido nenhum vértice
                        ultimo_vt = Insere_Vertice_fim(&Grafo,v,Grafo.inicio);
                    else
                        ultimo_vt = Insere_Vertice_fim(&Grafo,v,ultimo_vt);
                }
                else if(inserir == 'I')
                {
                    printf("Digite o numero do vertice: ");
                    scanf("%d",&v);
                    ultimo_vt = Insere_Vertice_inicio(&Grafo,G.inicio);
                }
                else if(inserir == 'O')
                {

                }
                inicializa_vertices(ultimo_vt);

                printf("R - para retornar ao menu.\n");
                scanf(" %s",acao);
            }while(acao == 'R');
        }

        //escolheu remover vértice
        if(acao == 'RV' || acao == 'rv')
        {
            do{
                printf("Para remover do fim, digite F.\n");
                printf("Para remover do inicio, digite I.\n");
                printf("Para remover um determinado numero de vertice, digite N.\n");
                scanf(" %s",remover);

                if(remover == 'F')
                {
                    ultimo_vt = Remove_Vertice_fim(&Grafo,ultimo_vt);
                }
                else if(remover == 'I')
                {

                }
                else if(remover == 'N')
                {

                }
                printf("R - para retornar ao menu.\n");
                scanf(" %s",acao);
            }while(acao != 'R');
        }

        //escolheu inserir aresta (insere as arestas no fim)
        if(acao == 'IA' || acao == 'ia')
        {
            do{
                printf("Digite o numero do vertice vizinho: ");
                scanf("%d",a);

                if(Grafo.inicio.inicio == NULL)
                    ultima_a = Insere_Aresta_fim(&Grafo,Grafo.inicio,a,Grafo.inicio.inicio);
                else
                    ultima_a = Insere_Aresta_fim(&Grafo,Grafo.inicio,a,ultima_a);

                printf("R - para retornar ao menu.\n");
                scanf(" %s",acao);
            } while(acao != 'R');
        }

        if(acao == 'RA' || acao == 'ra')
        {
            do{

                printf("R - para retornar ao menu.\n");
                scanf(" %s",acao);

            } while(acao != 'R');
        }

        if(acao == 'VG' || acao == 'vg')
        {
            do{
                VerGrafo(&Grafo);

                printf("R - para retornar ao menu.\n");
                scanf(" %s",acao);

            } while(acao != 'R');
        }

        printf("S ou s - para sair.\n");
        scanf(" %s",acao);

    }while(acao != 'S' || acao != 's');

    if(acao == 'S' || acao == 's')
    {
        clear;
        exit;
    }

    return 0;
}
