#include <stdio.h>
#include <stdlib.h>
 
 
int main()
{
	int t;
	long long unsigned int n,c;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%llu",&n);
		n=n+1;
		c=(n*(n+1))/2;
		
		printf("%llu\n",c-1);
	}
}