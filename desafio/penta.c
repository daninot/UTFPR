#include <stdio.h>

int main (void)
{
    int N, P, i;

    while(scanf("%d %d",&N,&P) == 2 && N != 0 && P != 0)
    {
        int jogadores[24];
        for(i=0;i<=23;i++)
            jogadores[i] = 0;

        for(i=1;i<=N;i++)
            jogadores[i]++;
        

    }
    return 0;
}
