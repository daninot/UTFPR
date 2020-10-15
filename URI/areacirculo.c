#include <stdio.h>

int main(void)
{
    double n = 3.14159, Raio, Area;
    scanf("%lf",&Raio);
    Area = n * (Raio * Raio);
    printf("A=%.4lf\n",Area);

    return 0;
}
