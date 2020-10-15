#include <stdio.h>

int main (void)
{
    double pi=3.14159, raio, volume;
    scanf("%lf",&raio);
    volume = (4/3.0) * pi * (raio * raio * raio);
    printf("VOLUME = %.3lf\n",volume);

    return 0;
}
