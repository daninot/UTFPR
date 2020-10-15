#include <stdio.h>
#include <stdlib.h>
#define Vertice int
#define Aresta int
#define true 1
#define false 0
#define libera(p) if(p != NULL){ free(p); p=NULL;}else printf("ops possivel DOUBLE FREE\n");
#define MAX 10
static int controle_vertices[MAX+1];
static int cor[MAX+1];
static int d[MAX+1];
static int pi[MAX+1];
static int f[MAX+1];
static int key[MAX+1];
static int tempo;
static char matriz[MAX+1][MAX+1];

//lista de adjacência de cada vértice
typedef struct arestas
{
    Aresta aresta;             //representa o vértice de entrada
    int peso;
    struct vertices *link;      //ponteiro para o vértice de mesmo número da aresta
    struct arestas *prox;
}arestas;

//lista dos vértices
typedef struct vertices
{
    Vertice vert;
    int qtd_vizinhos;           //quantidade de arestas que tem um vértice
    arestas *inicio;
    struct vertices *prox, *ant;
}vertices;

typedef struct grafo
{
    vertices *inicio;       //início da lista dos vértices
}grafo;

void inicializa_vertices(vertices *V)
{
    V->inicio = NULL;
    V->prox = NULL;
    V->ant = NULL;
    V->qtd_vizinhos = 0;
}

void inicializa_grafo(grafo *G)
{
    G->inicio = NULL;
}

//insere um vértice no fim da lista(passa como parâmetro sempre o vértice final)
vertices* Insere_Vertice_fim(grafo *G, Vertice V, vertices *ultimo)
{
    vertices *novoV = (vertices*)malloc(sizeof(vertices));
    inicializa_vertices(novoV);
    if(novoV == NULL)       //se a alocação não funcionar
        return NULL;
    else if(G->inicio == NULL)  //se eu entrar com o início do grafo e não houver nenhum vértice ainda
    {
        novoV->vert = V;
        novoV->prox = NULL;
        novoV->ant = NULL;
        G->inicio = novoV;
        return novoV;
    }
    novoV->vert = V;
    novoV->prox = NULL;
    ultimo->prox = novoV;
    novoV->ant = ultimo;
    return novoV;
}

//remove um vértice do fim da lista(passa como parâmetro o último velho e retorna o último novo)
vertices* Remove_Vertice_fim(grafo *G, vertices *ultimo)
{
    if(ultimo == NULL)          //caso o usuário seja sacana e me passe uma lista vazia
        return NULL;
    else if(ultimo->ant == NULL)     //caso só tenha um vértice na lista
    {
        libera(ultimo);
        return NULL;            //esvaziou a lista
    }
    vertices *aux = ultimo->ant;       //o aux é o penúltimo
    aux->prox = NULL;
    libera(ultimo);
    return aux;                        //agora o aux é o último
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
            libera(G->inicio);
            return 1;
        }
        G->inicio = G->inicio->prox;
        libera(tmp);
        return 1;
    }
}

//função remove qualquer vértice do grafo
int Remove_Qualquer_Vertice(grafo *G, vertices *aleatorio)
{
    vertices *tmp = aleatorio;
    aleatorio->ant->prox = aleatorio->prox;
    aleatorio->prox->ant = aleatorio->ant;
    libera(tmp);
    return 1;
}

//função procura um vértice no grafo
vertices* procuravertice(grafo *G, Vertice v)
{
    if(v > MAX)     //se o usuário entrar com um valor de vértice maior que o tamanho máximo do grafo
    {
        printf("Este vertice nao existe\n");
        return NULL;
    }
    else
    {
        if(controle_vertices[v] == 0)   //se no índice de número v do vetor de controle for 0 é pq o vértice não existe
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
int Insere_Aresta_fim(grafo *G, vertices *V, Aresta A, vertices *a, int p)
{
    arestas *novaA = (arestas*)malloc(sizeof(arestas));
    if(novaA == NULL)       //se a alocação não der certo
        return 0;
    if(V->inicio == NULL)  //se eu entrar com o início da lista de adjacência e não houver nenhuma aresta
    {
        novaA->aresta = A;
        novaA->peso = p;
        novaA->link = a;        //link aponta para o vértice no grafo de mesmo número da aresta
        novaA->prox = NULL;
        V->inicio = novaA;
        return 1;
    }
    else
    {
        arestas *aux = V->inicio;
        while(aux != NULL && aux->prox != NULL)     //percorro a Adj[V]
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
            novaA->peso = p;
            novaA->link = a;
            novaA->prox = NULL;
            aux->prox = novaA;
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
    if(V->inicio->aresta == A)      //se a aresta que deseja remover já for a inicial da Adj[V]
    {
        tmp = aux->prox;
        V->inicio = tmp;
        libera(aux);
        return 1;
    }
    else
    {
        while(aux != NULL)      //percorro a Adj[v] até encontrá-la
        {
            if(aux->aresta == A)
            {
                tmp->prox = aux->prox;
                libera(aux);
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
        printf(">%d, %d    ",A->aresta,A->peso);
        A = A->prox;
    }
}

//imprime o grafo; passa como parâmetro o primeiro vértice da lista
void VerGrafo(grafo *G, vertices *V)
{
    printf(" Vertice      Aresta, Peso\n");
    while(V != NULL)
    {
        printf("    %d          ",V->vert);
        VerArestas(V->inicio);
        V = V->prox;
        printf("\n");
    }
    printf("\n");
}

//####################FUNÇÕES PARAMETRIZADAS USADAS NA MAIN####################
//função de inserção de vértices (insere no fim)
vertices* funcao_insere_vertice(grafo *G, Vertice v, vertices *ultimo_vt)
{
    if(G->inicio == NULL)    //caso ainda não tenha sido inserido nenhum vértice no grafo
    {
        ultimo_vt = Insere_Vertice_fim(G,v,G->inicio);
        controle_vertices[v] = 1;
        printf("\nVertice inserido com sucesso!\n");
        return ultimo_vt;
    }
    else        //já houve inserção de vértices
    {
        if(controle_vertices[v] == 1)  //verificação da existência de um vértice pelo vetor de controle
        {
            printf("\nDesculpe, mas voce ja inseriu este vertice.\n\n");
            return NULL;
        }
        else
        {
            ultimo_vt = Insere_Vertice_fim(G,v,ultimo_vt);
            controle_vertices[v] = 1;
            printf("\nVertice inserido com sucesso!\n");
            return ultimo_vt;       //sempre retorna o último vértice inserido
        }
    }
}

//função de remoção de vértices
int funcao_remove_vertice(grafo *G, vertices *ultimo_vt, Vertice remover)
{
    if(remover == G->inicio->vert)    //se o vértice para remover for o primeiro do grafo
    {
        arestas *x = G->inicio->inicio;
        while(x != NULL)                    //primeiro preciso excluir a vizinhança do vértice com outros vértices
        {
            vertices *tmp = x->link;    //a aresta já tem um ponteiro pro vértice de mesmo número que ela
            RemoveAresta(G,tmp,remover);  //remove do vértice tmp a aresta com o vértice prestes a ser excluído
            tmp->qtd_vizinhos--;
            x = x->prox;
        }
        Remove_Vertice_inicio(G);           //finalmente removo o vértice
        controle_vertices[remover] = 0;     //zera o controle_vertices p/ indicar q o vértice n existe
        printf("\nVertice removido com sucesso!\n");
        return 1;
    }
    else if(remover == ultimo_vt->vert)     //se o vértice pra remover for o último vértice
    {
        arestas *x = ultimo_vt->inicio;
        while(x != NULL)                //excluo a vizinhança com outros vértices
        {
            vertices *tmp = x->link;
            RemoveAresta(G,tmp,remover);  //remove do vértice tmp a aresta com o vértice prestes a ser excluído
            tmp->qtd_vizinhos--;
            x = x->prox;
        }
        ultimo_vt = Remove_Vertice_fim(G,ultimo_vt);    //removo o vértice do fim do grafo e agora tenho um novo último
        controle_vertices[remover] = 0;
        printf("\nVertice removido com sucesso!\n");
        return 1;
    }
    else        //se não for o primeiro nem o último, o vértice a ser removido está no ~meio~ do grafo
    {
        vertices *aux = procuravertice(G,remover);
        if(aux != NULL)     //procurou e encontrou o vértice no grafo
        {
            if(aux->inicio != NULL)     //tem Adj[V]
            {
                arestas *x = aux->inicio;
                while(x != NULL)        //percorro a Adj[V] pra excluir as vizinhanças com o vértice a ser removido
                {
                    vertices *tmp = x->link;
                    RemoveAresta(G,tmp,remover);
                    tmp->qtd_vizinhos--;
                    x = x->prox;
                }
            }
            Remove_Qualquer_Vertice(G,aux);
            controle_vertices[remover] = 0;
            printf("\nVertice removido com sucesso!\n");
            return 1;
        }
        else    //procurou e não encontrou o vértice no grafo
        {
            printf("Impossivel remover.\n");
            return 0;
        }
    }
}

//função de inserção de arestas num vértice
int funcao_insere_aresta(grafo *G, Vertice v1, Vertice v2, int p)
{
    vertices *aux1 = procuravertice(G,v1);  //primeiro procuro os dois vértices que terão vizinhança
    vertices *aux2 = procuravertice(G,v2);

    int ret;
    if(aux1 != NULL && aux2 != NULL)     //se ele encontrou OS DOIS vértices
    {
        ret = Insere_Aresta_fim(G,aux1,v2,aux2,p);      //insiro primeiro em um vértice
        if(ret != 0)        //se inseriu OK
        {
            aux1->qtd_vizinhos++;
            ret = Insere_Aresta_fim(G,aux2,v1,aux1,p);  //insiro por segundo no outros
            aux2->qtd_vizinhos++;
            printf("Aresta inserida com sucesso!\n");
            return 1;
        }
    }
    else    //não encontrou OS DOIS vértices
    {
        printf("\nImpossivel inserir aresta.\n");
        return 0;
    }
}

//função de remoção de aresta
int funcao_remove_aresta(grafo *G, Vertice v, Vertice a)
{
    vertices *aux = procuravertice(G,a);       //primeiro procuro os dois vértices
    vertices *aux2 = procuravertice(G,v);

    if(aux != NULL && aux2 != NULL)     //se ele encontrou os dois vértices
    {
        RemoveAresta(G,aux,v);          //removo a vizinhança primeiro de um
        aux->qtd_vizinhos--;
        RemoveAresta(G,aux2,a);         //depois do outro
        aux->qtd_vizinhos--;
        printf("\nVizinhanca removida com sucesso!\n");
        return 1;
    }
    else    //não encontrou os dois vértices
    {
        printf("\nImpossivel remover.\n");
        return 0;
    }
}

//~~~~~~~~~~~~~~estrutura de lista usada na BFS~~~~~~~~~~~~~~~~~~
typedef struct lista
{
    Vertice Q[MAX];
    int cont, inicio, fim;
}lista;
void inicializa_lista(lista *l)
{
    l->cont=0;
    l->inicio=0;
    l->fim=0;
}
int esta_vazia(lista *l)
{
    if(l->cont==0)
        return true;
    return false;
}
int enfila(lista *l, Vertice elem)
{
    if(l->cont > MAX)
        return false;
    if(l->cont != 0) //pra eu não ter L->inicio apontando num indice vazio e o L->fim apontando pro valor (caso em que insiro o primeiro numero)
        l->fim = (l->fim+1) % MAX;
    l->Q[l->fim] = elem;
    l->cont++;
    return true;
}
Vertice desenfila(lista *l)
{
    Vertice ret = l->Q[l->inicio];
    if(l->cont > 1)
        l->inicio = (l->inicio + 1) % MAX; //pra se ele estiver no último índice do vetor, ele continue no início do vetor
    l->cont--;
    return ret;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//função BUSCA EM LARGURA
void BFS(grafo *G, Vertice u)
{
    lista Fila;
    inicializa_lista(&Fila);
    vertices *h = G->inicio;

    //inicialização
    while(h != NULL)
    {
        d[h->vert] = -1;
        cor[h->vert] = 98;     //branco
        pi[h->vert] = -1;
        h = h->prox;
    }
    d[u] = 0;    //vértice raiz tem distancia 0
    cor[u] = 99;    //cinza

    //processo
    enfila(&Fila,u);    //enfilo primeiro a raiz
    while(esta_vazia(&Fila) == false)
    {
        u = desenfila(&Fila);
        h = procuravertice(G,u);      //vou procurar o u desenfilado no meu grafo
        arestas *a = h->inicio;       //faço uma variável carregar o início das arestas dele
        while(a != NULL)
        {
            if(cor[a->aresta] == 98)    //se cor[aresta] == branco
            {
                cor[a->aresta] = 99;    //cor[aresta] = cinza
                d[a->aresta] = d[u] + 1;
                pi[a->aresta] = u;         //árvore busca largura
                enfila(&Fila,a->aresta);
            }
            a = a->prox;
        }
        cor[u] = 112;    //cor[vértice] = preto
    }

    //imprime
    printf("v       T[v]      d[v]\n");
    for(int i=1; i<=MAX; i++)
        printf("%d       %d        %d\n",i,pi[i],d[i]);
    printf("\n");
}

//parte recursiva da busca em profundidade (logo abaixo)
void DFSvisit(grafo *G, vertices *v)
{
    cor[v->vert] = 99;      //cor = cinza
    tempo = tempo + 1;
    d[v->vert] = tempo;

    arestas *a = v->inicio;
    while(a != NULL)        //percorro as arestas
    {
        if(cor[a->aresta] == 98)    //se cor == branco
        {
            pi[a->aresta] = v->vert;
            DFSvisit(G,a->link);    //a->link é um ponteiro para o vértice de mesmo número da aresta
        }
        a = a->prox;
    }
    cor[v->vert] = 112;     //cor = preto
    tempo = tempo + 1;
    f[v->vert] = tempo;
}
//função BUSCA EM PROFUNDIDADE
void DFS(grafo *G)
{
    vertices* h = G->inicio;
    while(h != NULL)            //inicializo os vetores
    {
        cor[h->vert] = 98;      //cor branca
        pi[h->vert] = -1;       //pais -1
        d[h->vert] = 0;
        f[h->vert] = 0;
        h = h->prox;
    }
    tempo = 0;
    h = G->inicio;
    while(h != NULL)        //percorro o grafo
    {
        if(cor[h->vert] == 98)      //se cor == branco
            DFSvisit(G,h);
        h = h->prox;
    }
}

//função verifica se o grafo é conexo
int conexo(grafo *G)
{
    vertices *aux = G->inicio;
    if(aux == NULL)     //se o grafo não tiver vértices -> não é conexo
        return 0;
    while(aux != NULL)
    {
        if(aux->qtd_vizinhos == 0)      //se o grau de algum vértice for 0 -> não é conexo
            return 0;
        aux = aux->prox;
    }
    aux = G->inicio;
    DFS(G);     //faz uma busca em profundidade pra ver se visita todos os vértices para ser conexo
    for(int i=0; i<MAX; i++)
    {
        if(cor[i] != 112)   //se algum não tiver a cor preta (de visitado) -> não é conexo
            return 0;
    }
    return 1;
}

//função que retorna o grau de um vértice
int grauvertice(grafo *G, Vertice v)
{
    if(controle_vertices[v] == 0)       //se o usuário inserir um vértice que não existe
    {
        printf("Lamento, mas este vertice nao existe.\n");
        return -1;
    }
    else
    {
        vertices *aux = procuravertice(G,v);
        return aux->qtd_vizinhos;
    }
}

//função que printa a matriz de adjacência do grafo
//OBS: Começa do 1.
void matrizadj(grafo *G)
{
    char *matriz[MAX+1][MAX+1];
    vertices *aux = G->inicio;
    arestas *tmp;
    for(int i=1; i<=MAX; i++)   //linha
        for(int j=1; j<=MAX; j++)   //coluna
            matriz[i][j] = "-";
    while(aux != NULL)
    {
        tmp = aux->inicio;
        while(tmp != NULL)
        {
            matriz[aux->vert][tmp->aresta] = "1";
            matriz[tmp->aresta][aux->vert] = "1";
            tmp = tmp->prox;
        }
        aux = aux->prox;
    }
    for(int i=1; i<=MAX; i++)
    {
        for(int j=1; j<=MAX; j++)
            printf("%s  ",matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}

//~~~~~~~~~~~~~~~~~~estrutura para fila de prioridade~~~~~~~~~~~~~~~~~~~~
typedef struct node_t
{
    int priority;   //prioridade do vértice na fila
    vertices *data;
}node_t;

typedef struct heap_t   //cabeça da lista de node_t
{
    node_t *nodes;
    int len;        //conta quantos vértices tem
    int size;       //quantidade não setada - assim que dá certo
}heap_t;

//enfila o novo node_t
void push(heap_t *h, int priority, vertices *data)
{
    if(h->len + 1 >= h->size)   //se a quantidade de vértices for maior que size ele realoca a memória
    {
        h->size = h->size ? h->size * 2 : 4;
        h->nodes = (node_t *)realloc(h->nodes, h->size * sizeof (node_t));
    }
    int i = h->len + 1;
    int j = i / 2;
    while (i > 1 && h->nodes[j].priority > priority)    //se o vértice a ser inserido tem prioridade menor que outro na fila ele vai adequar a ordem
    {
        h->nodes[i] = h->nodes[j];
        i = j;
        j = j / 2;
    }
    h->nodes[i].priority = priority;    //adiciona no fim
    h->nodes[i].data = data;
    h->len++;
}
//desenfila
vertices* pop(heap_t *h)
{
    int i, j, k;
    if(h->len == 0) //se a fila está vazia
        return NULL;

    vertices *data = h->nodes[1].data;  //pega o primeiro vértice da fila
    h->nodes[1] = h->nodes[h->len];     //copia os valores do último vértice da fila no primeiro lugar
    h->len--;
    i = 1;
    //agora vai arrumar a ordenação das prioridades na fila
    while(1)    //loop infinito acaba só quando k == i
    {
        k = i;
        j = 2 * i;
        if(j <= h->len && h->nodes[j].priority < h->nodes[k].priority)
            k = j;
        if(j + 1 <= h->len && h->nodes[j + 1].priority < h->nodes[k].priority)
            k = j + 1;
        if(k == i)
            break;

        h->nodes[i] = h->nodes[k];
        i = k;
    }
    h->nodes[i] = h->nodes[h->len + 1];
    return data;    //retorna o vértice com a menor prioridade
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//função para ÁRVORE GERADORA MÍNIMA
void Prim(grafo *G, vertices *raiz)
{
    vertices *u = G->inicio;
    heap_t *h = (heap_t *)calloc(1, sizeof (heap_t));
    int existe[MAX+1];
    h->len=0;
    while(u != NULL)
    {
        key[u->vert] = 100000;
        pi[u->vert] = -1;
        existe[u->vert] = 1;
        u = u->prox;
    }
    key[raiz->vert] = 0;
    push(h,key[raiz->vert],raiz);
    while(h->len > 0)
    {
        u = pop(h);
        existe[u->vert] = 0;        //sempre que desenfilo o menor, existe[vértice desenfilado] = 0
        arestas *v = u->inicio;
        while(v != NULL)
        {
            if(existe[v->aresta] == 1 && v->peso < key[v->aresta])  //pra verificar aqui se eu posso substituir um peso de uma aresta
            {                                                       //equivalente à existe do vértice na fila Q
                pi[v->aresta] = u->vert;
                key[v->aresta] = v->peso;
                push(h,key[v->aresta],v->link);     //enfilo (a prioridade é o valor de key)
            }
            v = v->prox;
        }
    }
    printf("v      T[v]     key[v]\n");
    for(int i=1; i<=MAX; i++)
        printf("%d       %d        %d\n",i,pi[i],key[i]);
    printf("\n");
}
/*como na linha 674 o push vai enfilar elementos repetidos e com possíveis valores de pesos
ultrapassados, o vetor existe garante o status de "vértice desenfilado", pois quando o valor
no índice do vértice == 0, quer dizer que eu já o desenfilei. */

//função para  CAMINHO MÍNIMO
void dijkstra(grafo *G, vertices *raiz)
{
    vertices *u = G->inicio;
    heap_t *h = (heap_t *)calloc(1, sizeof (heap_t));
    h->len=0;
    while(u != NULL)        //inicializo os vetores
    {
        d[u->vert] = 10000;
        pi[u->vert] = -1;
        cor[u->vert] = 98;      //branco
        u = u->prox;
    }
    d[raiz->vert] = 0;
    push(h,d[raiz->vert],raiz);
    while(h->len > 0)
    {
        u = pop(h);     //desenfilo o vértice de menor d
        cor[u->vert] = 112;     //preto
        arestas *v = u->inicio;
        while(v != NULL)    //percorro a Adj[u]
        {
            if(d[v->aresta] > (d[u->vert] + v->peso) && cor[v->aresta] != 112)
            {
                pi[v->aresta] = u->vert;
                d[v->aresta] = d[u->vert] + v->peso;
                cor[v->aresta] = 99;    //cinza
                push(h,d[v->aresta],v->link);  //enfilo (a prioridade é o d)
            }
            v = v->prox;
        }
    }
    printf("v      T[v]     d[v]\n");
    for(int i=1; i<=MAX; i++)
        printf("%d       %d        %d\n",i,pi[i],d[i]);
    printf("\n");
}

int main(void)
{
    grafo Grafo;
    inicializa_grafo(&Grafo);
    char acao;
    vertices *ultimo_vt = NULL;
    int qtd = 10;
    for(int v=1; v<=qtd; v++)
    {
        ultimo_vt = funcao_insere_vertice(&Grafo,v,ultimo_vt);
    }
    //1
    funcao_insere_aresta(&Grafo,1,2,7);
    funcao_insere_aresta(&Grafo,1,4,9);
    funcao_insere_aresta(&Grafo,1,5,10);
    funcao_insere_aresta(&Grafo,1,6,8);
    funcao_insere_aresta(&Grafo,1,8,9);
    funcao_insere_aresta(&Grafo,1,10,8);
    //2
    funcao_insere_aresta(&Grafo,2,3,4);
    funcao_insere_aresta(&Grafo,2,4,5);
    funcao_insere_aresta(&Grafo,2,9,9);
    funcao_insere_aresta(&Grafo,2,10,9);
    //3
    funcao_insere_aresta(&Grafo,3,4,1);
    funcao_insere_aresta(&Grafo,3,5,4);
    //4
    funcao_insere_aresta(&Grafo,4,5,3);
    //5
    funcao_insere_aresta(&Grafo,5,6,18);
    //6
    funcao_insere_aresta(&Grafo,6,8,9);
    funcao_insere_aresta(&Grafo,6,7,9);
    //7
    funcao_insere_aresta(&Grafo,7,9,6);
    funcao_insere_aresta(&Grafo,7,8,3);
    //8
    funcao_insere_aresta(&Grafo,8,9,4);
    funcao_insere_aresta(&Grafo,8,10,2);
    //9
    funcao_insere_aresta(&Grafo,9,10,2);


    printf("Ola. O que deseja fazer?\n");
    do
    {
        system("clear");

        printf("A ou a - Inserir um vertice.\n");
        printf("B ou b - Remover um vertice.\n");
        printf("C ou c - Inserir aresta.\n");
        printf("D ou d - Remover aresta.\n");
        printf("E ou e - Visualizar o grafo.\n");
        printf("F ou f - Informar grau de um vertice.\n");
        printf("G ou g - Informar se o grafo eh conexo.\n");
        printf("H ou h - Matriz de adjacencia.\n");
        printf("I ou i - Busca em Largura.\n");
        printf("J ou j - Busca em Profundidade.\n");
        printf("K ou k - Caminho minimo.\n");
        printf("L ou l - Arvore geradora minima.\n");
        printf("S ou s - para sair.\n");
        scanf(" %c",&acao);

        //escolheu inserir um vértice
        while(acao == 'A' || acao == 'a')
        {
            system("clear");
            Vertice v;
            printf("Digite o numero do vertice: ");
            scanf("%d",&v);

            ultimo_vt = funcao_insere_vertice(&Grafo,v,ultimo_vt); //retorna o último vértice do Grafo

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

            funcao_remove_vertice(&Grafo,ultimo_vt,remover);

            printf("\nPara continuar removendo: B ou b.\nR ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu inserir aresta (insere as arestas no fim)
        while(acao == 'C' || acao == 'c')
        {
            system("clear");

            Vertice v1, v2;
            int p;
            printf("Digite o numero do vertice 1: ");
            scanf("%d",&v1);
            printf("Digite o numero do vertice 2: ");
            scanf("%d",&v2);
            printf("Digite o numero do peso da aresta: ");
            scanf("%d",&p);

            funcao_insere_aresta(&Grafo,v1,v2,p);

            printf("\nPara continuar inserindo arestas: C ou c.\nR ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu remover aresta
        while(acao == 'D' || acao == 'd')
        {
            system("clear");

            Vertice v, a, result;
            printf("Qual aresta deseja remover? ");
            scanf("%d",&a);
            printf("Com qual vertice? ");
            scanf("%d",&v);

            funcao_remove_aresta(&Grafo,v,a);

            printf("\nPara continuar removendo arestas: D ou d.\nR ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu ver o grafo
        while(acao == 'E' || acao == 'e')
        {
            system("clear");
            VerGrafo(&Grafo,Grafo.inicio);
            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu ver o grau de um vertice
        while(acao == 'F' || acao == 'f')
        {
            system("clear");
            Vertice qual;
            printf("De qual vertice deseja saber o grau? ");
            scanf("%d",&qual);
            int grau = grauvertice(&Grafo,qual);
            if(grau != -1)
                printf("Este vertice tem grau %d.\n",grau);
            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu ver se o grafo é conexo
        while(acao == 'G' || acao == 'g')
        {
            system("clear");
            int ret = conexo(&Grafo);
            if(ret == 0)
                printf("Nao eh conexo.\n");
            else
                printf("Eh conexo.\n");
            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu ver a matriz de adjacência
        while(acao == 'H' || acao == 'h')
        {
            system("clear");
            matrizadj(&Grafo);
            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu a busca em largura
        while(acao == 'I' || acao == 'i')
        {
            system("clear");
            int raiz;
            printf("Qual eh o vertice raiz? ");
            scanf("%d",&raiz);
            BFS(&Grafo,raiz);
            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu a busca em profundidade
        while(acao == 'J' || acao == 'j')
        {
            system("clear");

            DFS(&Grafo);
            printf("v   d[v]    f[v]    T[v]\n");
            for(int i=1; i<=MAX; i++)
                printf("%d     %d      %d     %d\n",i,d[i],f[i],pi[i]);
            printf("\n");
            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu caminho mínimo
        while(acao == 'K' || acao == 'k')
        {
            system("clear");
            int r;
            printf("Insira a raiz: ");
            scanf("%d",&r);
            vertices *raiz = procuravertice(&Grafo,r);
            dijkstra(&Grafo,raiz);
            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        //escolheu a árvore geradora mínima
        while(acao == 'L' || acao == 'l')
        {
            system("clear");
            int r;
            printf("Insira a raiz: ");
            scanf("%d",&r);
            vertices *raiz = procuravertice(&Grafo,r);
            Prim(&Grafo,raiz);
            printf("R ou r para retornar ao menu.\n");
            scanf(" %c",&acao);
        }

        system("clear");

        if(acao == 'S' || acao == 's')
            return(0);
    }while(acao != 'S' || acao != 's');
    return 0;
}
