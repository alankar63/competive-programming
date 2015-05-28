#include <stdio.h>
 
long long int ans(long long int b,long long int n,long long int M)
{
	long long int sol=1;
	while(n>0)
	{
		if(n%2==1)
		{
			sol=(sol*b)%M;
			
		}
		b=(b*b)%M;
		n=n>>1;
	}
	
	return sol;
}
 
int main(void)
{
	int t;
	long long int n,val;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		val=ans(2,n,1000000007);
		val--;
		printf("%lld\n",val);
	}
	return 0;
}