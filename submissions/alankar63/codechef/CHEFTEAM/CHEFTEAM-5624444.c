#include<stdio.h>
unsigned long long gcd(unsigned long long a ,unsigned long long b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
main()
{
	int test;
	scanf("%d",&test);
	unsigned  long long n,k;
	unsigned long long ans;
	unsigned long long i;
	unsigned long long d,temp,temp1;
	while(test--)
	{
		scanf("%llu",&n);
		scanf("%llu",&k);
		if(n<k)
		{
			printf("0\n");
			continue;
		}
		ans=1;
		if(k>n-k)
			k=n-k;
		for(i=1;i<=k;++i)
		{
			if(ans>=i)
				d=gcd(ans,i);
			else
				d=gcd(i,ans);
			//	printf("%lld\n",d);
			ans=ans/d;
			//		temp=i/d;
			//		temp1=(n-i+1)/temp;
			ans=ans*((n-i+1)/(i/d));
 
		}
		printf("%llu\n",ans);
 
	}
 
}