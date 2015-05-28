#include <stdio.h>
 
int main(void) {
	long long int n,sum,i;
	scanf("%lld",&n);
	long long s;
	for (i=0;i<n;i++)
	{scanf("%lld ",&s);
	sum+=s;}
	if(sum==(n*(n+1)/2))
	printf("YES");
	else
		printf("NO");
	
	return 0;
}