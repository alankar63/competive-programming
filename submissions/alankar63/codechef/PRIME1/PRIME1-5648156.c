#include <stdio.h>
 
int main(void) {
	long long int t,n,m,arr[1000001],i,j,str;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		for(i=n;i<=m;i++)
		arr[i-n]=0;
		if(n==1)
		arr[0]=1;
		for(i=2;i*i<=m;i++)
		{
			if(n%i==0)
			str=n;
			else
			str=(n/i)*i+i;
			if(str==i)
			str+=i;
			for(j=str;j<=m;j+=i)
			{
				arr[j-n]=1;
			}
		}
		for(i=n;i<=m;i++)
		{
			if(arr[i-n]==0)
			printf("%lld\n",i);
		}
		printf("\n");
	}
	return 0;
}