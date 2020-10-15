#include <stdio.h>

int main(void)
{
    int Xm, Ym, Xr, Yr, result, aux;

    scanf("%d %d %d %d",&Xm,&Ym,&Xr,&Yr);

    if(Xm > Xr)
    {
        aux = Xm;
        Xm = Xr;
        Xr = aux;
    }
    if(Ym > Yr)
    {
        aux = Ym;
        Ym = Yr;
        Yr = aux;
    }

    result = (Xr - Xm) + (Yr - Ym);

    printf("%d\n",result);

    return 0;
}
