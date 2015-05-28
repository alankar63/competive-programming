#include <stdio.h>
 
int main(void) {
	long int t,n,p[100000],min,i;
	long long int ans;
	scanf("%ld",&t);
	while(t--)
	{
		ans=0; 
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&p[i]);
			ans+=p[i];
		}
		min=p[0];
		for(i=1;i<n;i++)
		{
			if(min>p[i])
			 min=p[i];
		}
		ans=ans-min;
		ans=ans*min;
		printf("%lld\n",ans);
	}
	return 0;
}