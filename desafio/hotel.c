#include <stdio.h>

int main(void)
{
    int S, D, i;

    while(scanf("%d %d",&S,&D) == 2)
    {
        while(D >= 0)
        {
            D = D - S;
            if(D > 0)
                S = S + 1;
        }
        printf("%d\n",S);
    }

    return 0;
}
