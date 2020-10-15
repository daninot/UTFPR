#include <stdio.h>

int main(void)
{
    int Cv, Ce, Cs, Fv, Fe, Fs, PtosC, PtosF;

    scanf("%d %d %d %d %d %d",&Cv,&Ce,&Cs,&Fv,&Fe,&Fs);

    PtosC = (3 * Cv) + Ce;
    PtosF = (3 * Fv) + Fe;

    if(PtosC > PtosF)
    {
        printf("C\n");
    }
    else if(PtosC == PtosF)
    {
        if(Cs > Fs)
        {
            printf("C\n");
        }
        else if(Cs == Fs)
        {
            printf("=\n");
        }
        else
        {
            printf("F\n");
        }
    }
    else
    {
        printf("F\n");
    }

    return 0;
}
