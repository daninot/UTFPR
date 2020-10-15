#include <stdio.h>

int main (void)
{
	int A, B, C;
	
	scanf("%d %d %d",&A,&B,&C);
	
	if(A > B && A > C)
	{
		if(B > C)
		{
			printf("%d\n",B);
		}
		else
		{
			printf("%d\n",C);
		}
	}
	if(B > A && B > C)
	{
		if(A > C)
		{
			printf("%d\n",A);
		}
		else
		{
			printf("%d\n",C);
		}
	}
	if(C > A && C > B)
	{
		if(A > B)
		{
			printf("%d\n",A);
		}
		else
		{
			printf("%d\n",B);
		}
	}
	
	return 0;
}
