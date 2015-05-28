#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long t,n,i;
	int flag;
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		scanf("%lld",&n);
		if((n%4)==1)
			printf("ALICE\n");
		else
			printf("BOB\n");
	}
	return 0;
}