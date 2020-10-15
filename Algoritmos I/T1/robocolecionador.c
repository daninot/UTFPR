#include <stdio.h>
#include <stdlib.h>

//função que retorna a orientação atual do robô
int muda_orientacao(int acao, int x, int y, char arena[][100], int oi)
{
    int orient;

    if(oi == 'N')
    {
        if(acao == 'D')
        {
            orient = 'L';
            return(orient);
        }
        else if(acao == 'E')
        {
            orient = 'O';
            return(orient);
        }
    }
    else if(oi == 'S')
    {
        if(acao == 'D')
        {
            orient = 'O';
            return(orient);
        }
        else if(acao == 'E')
        {
            orient = 'L';
            return(orient);
        }
    }
    else if(oi == 'L')
    {
        if(acao == 'D')
        {
            orient = 'S';
            return(orient);
        }
        else if(acao == 'E')
        {
            orient = 'N';
            return(orient);
        }
    }
    else if(oi == 'O')
    {
        if(acao == 'D')
        {
            orient = 'N';
            return(orient);
        }
        else if(acao == 'E')
        {
            orient = 'S';
            return(orient);
        }
    }
}

//função que retorna as novas coordenadas dele, já que ele andou (só chama a função quando entra com F)
void muda_coordenadas(int *x, int *y, char arena[][100], int orientacao)
{
    if(orientacao == 'N')
            *x = *x-1;
    
    else if(orientacao == 'S')
            *x = *x+1;
  
    else if(orientacao == 'L')
            *y = *y+1;
    
    else if(orientacao == 'O')
            *y = *y-1;
}

int main (void)
{
    int N, M, S, i, j, x, y, oi, orient, qtd;

    while(scanf("%d %d %d",&N,&M,&S) && (N != 0 && M != 0 && S != 0))
    {
        char arena[100][100], acao[S];

        //lê a arena
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                scanf(" %c",&arena[i][j]);
                if(arena[i][j] == 'N' || arena[i][j] == 'S' || arena[i][j] == 'L' || arena[i][j] == 'O')
                {
                    x = i;
                    y = j;
                    oi = arena[i][j];
                }
            }
        }

	for(i=0; i<S; i++)
		scanf(" %c",&acao[i]);
	
        qtd=0;
        for(i=0; i<S; i++)
        {
            if(acao[i] == 'E' || acao[i] == 'D')
            {
                orient = muda_orientacao(acao[i],x,y,arena,oi);
                oi = orient;
            }
            else if(acao[i] == 'F')
            {
            	if(oi == 'N')
            	{
            		if(x != 0 && arena[x-1][y] != '#')
                		muda_coordenadas(&x,&y,arena,oi);
                }
                else if(oi == 'S')
   		{
        		if(x != (N-1) && arena[x+1][y] != '#')
        			muda_coordenadas(&x,&y,arena,oi);
      		}
      		else if(oi == 'L')
    		{
       			if(y != (M-1) && arena[x][y+1] != '#')
       				muda_coordenadas(&x,&y,arena,oi);
       		}
       		else if(oi == 'O')
    		{
        		if(y != 0 && arena[x][y-1] != '#')
        			muda_coordenadas(&x,&y,arena,oi);
        	}

                if(arena[x][y] == '*')
                {
                    qtd++;
                    arena[x][y] = '.'; //pra saber que foi tirada uma figurinha dali
                }
            }
        }
        printf("%d\n",qtd);
    }
    return 0;
}
