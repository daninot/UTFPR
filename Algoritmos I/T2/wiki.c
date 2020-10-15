#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  struct no *prox;
  char item;
}no;

typedef struct lista
{
  no *inicio;
  int cont;
}lista;

void inicializa(lista *l)
{
  l->inicio=NULL;
  l->cont=0;
}

//se a lista estiver vazia ou item != do topo, eu empilho
void empilha(lista *l, char item)
{
  no *novo=(no*)malloc(sizeof(no));
  novo->item=item;
  novo->prox=l->inicio;
  l->inicio=novo;
  l->cont++;

}
//retorna o item do topo sem remove-lo

//problemas no topo eu achoooooooooooooooooooooo
char topo(lista *l)
{
  char ret=l->inicio->item;
  return ret;
}
//como o nome diz, *~desempilha~* (^-^) (arco-iris)
char desempilha(lista *l)
{
  char ret=l->inicio->item;
  no *aux=l->inicio;
  l->inicio=l->inicio->prox;
  free(aux);
  l->cont--;
  return ret;
}

int estavazia(lista *l)
{
 if(l->inicio==NULL)
 {
   return 1;
 }
 return 0;
}

// MAINNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNnha mainha mainha kkkkkk

int main (void)
{

  int n, i, j, errado=0;
  char enter;

  lista pilha;
  inicializa(&pilha);

  scanf("%d", &n);
  scanf("%c", &enter);

  for(i=1;i<=n;i++)
  {
    char frase[200000];
    fgets(frase, 200000, stdin);

    j=0;

    while(frase[j]!='\0')
    {
      //aq onde o bixo pega
      if(frase[j]=='_' || frase[j]=='*' || frase[j]=='/')
      {
        if(estavazia(&pilha)==1)
        {
          empilha(&pilha, frase[j]);
        }
        else
        {

          if(topo(&pilha)!=frase[j])
          {
            empilha(&pilha, frase[j]);
          }
          else
          {
            desempilha(&pilha);
          }
        }
      }

      j++;
    }

  }
  if(estavazia(&pilha)==0)
  {
    errado=1;
  }

  if(errado==0)
  {
    printf("C\n");
  }
  else
  {
    printf("E\n");
  }

  return 0;
}
