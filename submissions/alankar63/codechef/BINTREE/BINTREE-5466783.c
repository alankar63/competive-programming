//this is nice and based on editorial
#include <stdio.h>
int count(x)
{
	int count=0;
	while(x>=1)
	{
		count++;
		x=x>>1;
	}
	return count;
}	
int lca(x,y)
{
	int i,j,k,stop=0;
	for(i=x;i>=1;i=i=i>>1)
	{
		for(j=y;j>=1;j=j>>1)
		{
			if(i==j && stop==0)
			{
				k=count(i);
				stop=1;
			}
		}
	}
return k;
}
int main(void) {
	long long int n,x,y,len;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld %lld",&x,&y);
		len=count(x)+count(y)-2*lca(x,y);
		printf("%lld\n",len);
	}
	// your code goes here
	return 0;
}