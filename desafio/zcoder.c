#include <stdio.h>
#include <stdlib.h>
#define MAXF 1000
#define f_type int

typedef struct fila
{
    f_type vet[MAXF];
    int cont, inicio, fim;
}fila;

void inicializa_fila(fila *f)
{
    f->cont=0;
    f->inicio=0;
    f->fim=0;
}

int esta_vaziafila(fila *f)
{
    if(f->cont==0)
        return 1;
    return 0;
}

int enfila(fila *f, f_type elem)
{
    if(f->cont > MAXF)
        return 0;

    f->vet[f->fim] = elem;
    f->cont++;
    f->fim = ((f->fim+1) % MAXF);
    return 1;
}

f_type desenfila(fila *f)
{
    f_type ret;

    ret = f->vet[f->inicio];
    //if(f->cont > 1)
        f->inicio = (f->inicio+1) % MAXF;
    //f->inicio++;
    f->cont--;
    return ret;
}

int main (void)
{
    int N, c, z, i;
    //scanf("%d %d",&N,&c);
    if(scanf("%d %d",&N,&c) == 2 && (N > 0 && c > 0 && c <= 109)){
        //printf("escreva novamente\n");

    fila zcoder;
    inicializa_fila(&zcoder);
    for(i=0;i<N;i++)
    {
        while(scanf("%d",&z) == 1 && z >= 1 && z <= 109)
            enfila(&zcoder,z); i++;
    }

    for(i=1;i<N;i++)
    {
        printf("dif %d\n",(zcoder.vet[i] - zcoder.vet[i-1]));
        //printf("inicio %d\n",zcoder.inicio);

        if((zcoder.vet[i] - zcoder.vet[i-1]) > c )
        {
            //printf("hello\n");
            while(zcoder.inicio < i)
            {
                desenfila(&zcoder);
                //printf("inicio %d\n",zcoder.inicio);
                //printf("cont = %d\n",zcoder.cont);

            }
        }

    }
    printf("%d\n",zcoder.cont);
}
    return 0;
}
