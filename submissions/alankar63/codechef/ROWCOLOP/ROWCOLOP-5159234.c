#include<stdio.h>
long long int r[314165]={0},c[314165]={0};
int main()
{
	long long int rm,cm,n,t,a,b;
	scanf("%lld%lld",&n,&t);
	rm=cm=0;
	while(t--)
	{
		char s[15];
		scanf("%s%lld%lld",s,&a,&b);
		if(s[0]=='R')
		{
			r[a]=r[a]+b;
			if(r[a]>rm)
			rm=r[a];
		}
		if(s[0]=='C')
		{
			c[a]=c[a]+b;
			if(c[a]>cm)
			cm=c[a];
		}
	}
	printf("%lld",(rm+cm));
	return 0;
}