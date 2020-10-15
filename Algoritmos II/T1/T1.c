#include <stdio.h>
#include <stdlib.h>
#define Vertice int
#define Aresta Vertice
#define true 1
#define false 0
#define libera(p) if(p != NULL){ free(p); p=NULL;}else printf("ops possivel DOUBLE FREE\n");
#define MAX 9

//lista de adjacência de cada vértice;
typedef struct arestas
{
    Aresta aresta;             //representa o vértice de entrada
    struct arestas *prox;
}arestas;

//lista dos vértices
typedef struct vertices
{
    Vertice vert;
    int qtd_vizinhos;
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
    V->qtd_vizinhos = 0;
}

void inicializa_grafo(grafo *G)
{
    G->inicio = NULL;
    G->qtd_arestas = 0;
    G->qtd_vertices = 0;
}

//insere um vértice no fim da lista(passa como parâmetro sempre o vértice final)
vertices* Insere_Vertice_fim(grafo *G, Vertice V, vertices *ultimo)
{
    vertices *novoV = (vertices*)malloc(sizeof(vertices));
    inicializa_vertices(novoV);
    if(novoV == NULL)
        return NULL;
    else if(G->inicio == NULL)  //se eu entrar com o início do grafo e não houver nenhum vértice ainda
    {
        //printf("hello1\n");

        novoV->vert = V;
        novoV->prox = NULL;
        novoV->ant = NULL;
        G->inicio = novoV;
        //G->qtd_vertices++;
        return novoV;
    }
    //printf("hello2\n");

    novoV->vert = V;
    novoV->prox = NULL;
    ultimo->prox = novoV;
    novoV->ant = ultimo;
    //G->qtd_vertices++;
    return novoV;
}

//remove um vértice do fim da lista(passa como parâmetro o último velho e retorna o último novo)
vertices* Remove_Vertice_fim(grafo *G, vertices *ultimo)
{
    if(ultimo == NULL)          //caso ele seja sacana e me passe uma lista vazia
        return NULL;
    else if(ultimo->ant == NULL)     //caso só tenha um vértice na lista
    {
        libera(ultimo);
        return NULL;            //esvaziou a lista
    }
    vertices *aux = ultimo->ant;       //o aux é o penúltimo
    aux->prox = NULL;
    libera(ultimo);
    //G->qtd_vertices--;
    return aux;                        //agr o aux é o último
}

//função remove o vertice de inicio do grafo
int Remove_Vertice_inicio(grafo *G)
{
    if(G->inicio == NULL)   //caso não tenha nenhum vértice
    {
        printf("Voce precisa inserir vertices primeiro!\n");
        return 0;
    }
    else
    {
        vertices *tmp = G->inicio;

        if(G->inicio->prox == NULL)
        {
            //G->qtd_arestas = G->qtd_arestas - G->inicio->qtd_vizinhos;
            //G->qtd_vertices--;
            libera(G->inicio);
            return 1;
        }
        //G->qtd_arestas = G->qtd_arestas - G->inicio->qtd_vizinhos;
        //G->qtd_vertices--;
        G->inicio = G->inicio->prox;
        libera(tmp);
        return 1;
    }
}

//função remove quase vértice do grafo
int Remove_Qualquer_Vertice(grafo *G, vertices *aleatorio)
{
    vertices *tmp = aleatorio;
    aleatorio->ant->prox = aleatorio->prox;
    aleatorio->prox->ant = aleatorio->ant;
    //G->qtd_vertices--;
    //G->qtd_arestas = G->qtd_arestas - aleatorio->qtd_vizinhos;
    libera(tmp);
    return 1;
}

//função procura um vértice no grafo
vertices* procuravertice(grafo *G, int *controle_vertices, Vertice v)
{
    if(v > MAX)
    {
        printf("Este vertice nao existe\n");
        return NULL;
    }
    else
    {
        if(controle_vertices[v] == 0)
        {
            printf("Este vertice nao existe.\n");
            return NULL;
        }
        else
        {
            vertices *aux = G->inicio;
            while(aux != NULL && aux->vert != v)
                aux = aux->prox;
            return aux;
        }
    }
}

//insere uma aresta (um vértice de entrada) no fim da lista de adjacência (leque de saída)
int Insere_Aresta_fim(grafo *G, vertices *V, Aresta A)
{
    arestas *novaA = (arestas*)malloc(sizeof(arestas));

    if(novaA == NULL)
        return 0;
    if(V->inicio == NULL)  //se eu entrar com o início da lista de adjacência e não houver nenhuma aresta
    {
        novaA->aresta = A;
        novaA->prox = NULL;
        V->inicio = novaA;
        //V->qtd_vizinhos++;
        return 1;
    }
    else
    {
        arestas *aux = V->inicio;
        while(aux != NULL && aux->prox != NULL)
        {
            if(aux->aresta == A)
            {
                printf("\nJa existe vizinhanca entre os dois vertices!\n");
                return 0;
            }
            else if(A == V->vert)
            {
                printf("\nLacos nao sao permitidos.\n");
                return 0;
            }
            aux = aux->prox;
        }
        if(aux->aresta == A)
        {
            printf("\nJa existe vizinhanca entre os dois vertices!\n");
            return 0;
        }
        else
        {
            novaA->aresta = A;
            novaA->prox = NULL;
            aux->prox = novaA;
            //V->qtd_vizinhos++;
            return 1;
        }
    }
}

//função remove qualquer aresta
int RemoveAresta(grafo *G, vertices *V, Aresta A)
{
    arestas *aux = V->inicio;
    arestas *tmp;
    int i=0;
    if(V->inicio->aresta == A)
    {
        tmp = aux->prox;
        V->inicio = tmp;
        libera(aux);
        //V->qtd_vizinhos--;
        return 1;
    }
    else
    {
        while(aux != NULL)
        {
            if(aux->aresta == A)
            {
                tmp->prox = aux->prox;
                libera(aux);
                //V->qtd_vizinhos--;
                return 1;
            }
            tmp = aux;
            aux = aux->prox;
        }
    }
    return 0;
}

//imprime a lista de adjacências (leque de saída)
void VerArestas(arestas *A) //passa como parâmetro a primeira aresta da lista
{
    while(A != NULL)
    {
        printf("-> %d ",A->aresta);
        A = A->prox;
    }
}

//imprime o grafo; passa como parâmetro o primeiro vértice da lista
void VerGrafo(grafo *G, vertices *V)
{
    while(V != NULL)
    {
        printf("-----\n");
        printf(" %d   ",V->vert);
        VerArestas(V->inicio);
        V = V->prox;
        printf("\n");
    }
    printf("\n");
    //printf("Este grafo possui %d vértices e %d arestas.\n",G->qtd_vertices,G->qtd_arestas);
}

vertices* funcao_insere_vertice(grafo *G, Vertice v, vertices *ultimo_vt, int *controle_vertices)
{
    if(G->inicio == NULL)    //caso ainda não tenha sido inserido nenhum vértice no grafo
    {
        ultimo_vt = Insere_Vertice_fim(G,v,G->inicio);
        controle_vertices[v] = 1;
        printf("\nVertice inserido com sucesso!\n");
        inicializa_vertices(ultimo_vt);
        return ultimo_vt;
    }
    else        //já houve inserção de vértices
    {
        if(controle_vertices[v] == 1)
        {
            printf("\nDesculpe, mas voce ja inseriu este vertice.\n\n");
            return NULL;
        }
        else
        {
            ultimo_vt = Insere_Vertice_fim(G,v,ultimo_vt);
            controle_vertices[v] = 1;
            printf("\nVertice inserido com sucesso!\n");
            inicializa_vertices(ultimo_vt);
            return ultimo_vt;
        }
    }
}

int funcao_remove_vertice(grafo *G, vertices *ultimo_vt, Vertice remover, int *controle_vertices)
{
    if(remover == G->inicio->vert)    //se for o primeiro
    {
        arestas *x = G->inicio->inicio;
        while(x != NULL)
        {
            vertices *tmp = procuravertice(G,controle_vertices,x->aresta); //vai procurar o vértice deste número
            int ret = RemoveAresta(G,tmp,remover);  //remove daquele vértice a aresta com o vértice prestes a ser excluído
            x = x->prox;
        }
        Remove_Vertice_inicio(G);
        controle_vertices[remover] = 0;
        printf("\nVertice removido com sucesso!\n");
        return 1;
    }
    else if(remover == ultimo_vt->vert)     //se for o último vértice
    {
        arestas *x = ultimo_vt->inicio;
        while(x != NULL)
        {
            vertices *tmp = procuravertice(G,controle_vertices,x->aresta); //vai procurar o vértice deste número
            int ret = RemoveAresta(G,tmp,remover);  //remove daquele vértice a aresta com o vértice prestes a ser excluído
            x = x->prox;
        }
        ultimo_vt = Remove_Vertice_fim(G,ultimo_vt);
        controle_vertices[remover] = 0;
        printf("\nVertice removido com sucesso!\n");
        return 1;
    }
    else
    {
        vertices *aux = procuravertice(G,controle_vertices,remover);
        if(aux != NULL)
        {
            if(aux->inicio != NULL)
            {
                arestas *x = aux->inicio;
                while(x != NULL)
                {
                    vertices *tmp = procuravertice(G,controle_vertices,x->aresta); //vai procurar o vértice deste número
                    int ret = RemoveAresta(G,tmp,remover);  //remove daquele vértice a aresta com o vértice prestes a ser excluído
                    x = x->prox;
                }
            }
            Remove_Qualquer_Vertice(G,aux);
            controle_vertices[remover] = 0;
            printf("\nVertice removido com sucesso!\n");
            return 1;
        }
        else
        {
            printf("Impossivel remover.\n");
            return 0;
        }
    }
}

int funcao_insere_aresta(grafo *G, Vertice v1, Vertice v2, int *controle_vertices)
{
    vertices *aux = procuravertice(G,controle_vertices,v1);
    vertices *aux2 = procuravertice(G,controle_vertices,v2);
    int ret;
    if(aux != NULL && aux2 != NULL)     //se ele encontrou OS DOIS vértices
    {
        ret = Insere_Aresta_fim(G,aux,v2);
        if(ret != 0)
        {
            ret = Insere_Aresta_fim(G,aux2,v1);
            //G->qtd_arestas++;
            printf("Aresta inserida com sucesso!\n");
            return 1;
        }
    }
    else
    {
        printf("\nImpossivel inserir aresta.\n");
        return 0;
    }
}

int funcao_remove_aresta(grafo *G, Vertice v, Vertice a, int *controle_vertices)
{
    Vertice result;
    vertices *aux = procuravertice(G,controle_vertices,a);
    vertices *aux2 = procuravertice(G,controle_vertices,v);

    if(aux != NULL && aux2 != NULL)     //se ele encontrou os dois vértices
    {
        RemoveAresta(G,aux,v);
        RemoveAresta(G,aux2,a);
        //G->qtd_arestas--;
        printf("\nVizinhanca removida com sucesso!\n");
        return 1;
    }
    else
    {
        printf("\nImpossivel remover.\n");
        return 0;
    }
}

/*void mostra_controle_Vertices(int *controle_vertices,int tam)
{
    for(int i=0;i<=tam;i++)
        printf("controle_vertices[%d] = %d\n",i,controle_vertices[i]);
}*/

int main(void)
{
    grafo Grafo;
    inicializa_grafo(&Grafo);
    char acao;
    vertices *ultimo_vt = NULL;
    int controle_vertices[MAX+1];
    int qtd = 9;
    for(int v=1; v<=qtd; v++)
    {
        ultimo_vt = funcao_insere_vertice(&Grafo,v,ultimo_vt,controle_vertices);
    }
    //1
    funcao_insere_aresta(&Grafo,1,2,controle_vertices);
    funcao_insere_aresta(&Grafo,1,6,controle_vertices);
    //2
    funcao_insere_aresta(&Grafo,2,1,controle_vertices);
    funcao_insere_aresta(&Grafo,2,4,controle_vertices);
    funcao_insere_aresta(&Grafo,2,3,controle_vertices);
    //3
    funcao_insere_aresta(&Grafo,3,2,controle_vertices);
    funcao_insere_aresta(&Grafo,3,5,controle_vertices);
    //4
    funcao_insere_aresta(&Grafo,4,6,controle_vertices);
    funcao_insere_aresta(&Grafo,4,2,controle_vertices);
    funcao_insere_aresta(&Grafo,4,5,controle_vertices);
    funcao_insere_aresta(&Grafo,4,7,controle_vertices);
    //5
    funcao_insere_aresta(&Grafo,5,3,controle_vertices);
    funcao_insere_aresta(&Grafo,5,4,controle_vertices);
    //6
    funcao_insere_aresta(&Grafo,6,1,controle_vertices);
    funcao_insere_aresta(&Grafo,6,4,controle_vertices);
    //7
    funcao_insere_aresta(&Grafo,7,4,controle_vertices);
    funcao_insere_aresta(&Grafo,7,9,controle_vertices);
    funcao_insere_aresta(&Grafo,7,8,controle_vertices);
    //8
    funcao_insere_aresta(&Grafo,8,7,controle_vertices);
    //9
    funcao_insere_aresta(&Grafo,9,7,controle_vertices);


    printf("Ola. O que deseja fazer?\n");
    do
    {
        system("clear");

        printf("A ou a - para inserir um vertice.\n");
        printf("B ou b - para remover um vertice.\n");
        printf("C ou c - para inserir aresta.\n");
        printf("D ou d - para remover aresta.\n");
        printf("E ou e - para visualizar o grafo.\n");
        printf("S ou s - para sair.\n");
        scanf(" %c",&acao);

        //escolheu inserir um vértice
        while(acao == 'A' || acao == 'a')
        {
            system("clear");
            Vertice v;
            printf("Digite o numero do vertice: ");
            scanf("%d",&v);

            ultimo_vt = funcao_insere_vertice(&Grafo,v,ultimo_vt,controle_vertices);

            printf("\nPara continuar inserir: A ou a.\nR ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu remover vértice
        while(acao == 'B' || acao == 'b')
        {
            system("clear");
            Vertice remover;
            printf("Digite o numero do vertice que deseja remover: ");
            scanf("%d",&remover);

            funcao_remove_vertice(&Grafo,ultimo_vt,remover,controle_vertices);

            printf("\nPara continuar removendo: B ou b.\nR ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu inserir aresta (insere as arestas no fim)
        while(acao == 'C' || acao == 'c')
        {
            system("clear");

            Vertice v1, v2;
            printf("Digite o numero do vertice 1: ");
            scanf("%d",&v1);
            printf("Digite o numero do vertice 2: ");
            scanf("%d",&v2);

            funcao_insere_aresta(&Grafo,v1,v2,controle_vertices);

            printf("\nPara continuar inserindo arestas: C ou c.\nR ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        while(acao == 'D' || acao == 'd')
        {
            system("clear");

            Vertice v, a, result;
            printf("Qual aresta deseja remover? ");
            scanf("%d",&a);
            printf("De qual vertice? ");
            scanf("%d",&v);

            funcao_remove_aresta(&Grafo,v,a,controle_vertices);

            printf("\nPara continuar removendo arestas: D ou d.\nR ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        while(acao == 'E' || acao == 'e')
        {
            system("clear");

            VerGrafo(&Grafo,Grafo.inicio);

            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        system("clear");

        if(acao == 'S' || acao == 's')
            return(0);
    }while(acao != 'S' || acao != 's');
    return 0;
}
