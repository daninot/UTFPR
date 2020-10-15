#include <stdio.h>

int main (void)
{
    int N, M, A, K, m=0, a=0, k=0;
    scanf("%d %d %d %d",&N,&M,&A,&K);
    char carac;
    scanf(" %c",&carac);
    while(carac != '\0' && carac != '\n')
    {
        //printf("%c  ",carac);
        if(carac >= 97 && carac <= 122)
            m++;
        else if(carac >= 65 && carac <= 90)
            a++;
        else if(carac >= 48 && carac <= 57)
            k++;
        scanf("%c",&carac);
    }
    if((m+a+k) < N)
        printf("Ufa :)\n");
    else
    {
        if(m >= M && a >= A && k >= K)
        {
            printf("Ok =/\n");
        }
        else
            printf("Ufa :)\n");
    }

    return 0;
}
