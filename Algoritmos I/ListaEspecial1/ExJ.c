#include <stdio.h>

int main (void)
{
	long long int L, N, R;

	scanf("%lld %lld",&L,&N);

	R = ((L - N + 1) * (L - N + 1)) + (N - 1);

	printf("%lld\n",R);
	
	return 0;
}
