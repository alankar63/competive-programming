#include <stdio.h>
#include <string.h>
#define lim 500
#define mod 1000000007
#define LLD long long
LLD mypow(LLD a,LLD b)
{
	LLD temp;
	if(b==1)
	return a;
	else
	{
		temp=mypow(a,b/2);
		return ((temp*temp)%mod*(b&1?a:1))%mod;
	}
}
LLD fact[501];
LLD inv[501];
void calc()
{
	LLD f=1;
	int i;
	for(i=1;i<=lim;i++)
	{
		f=(f*i)%mod;
		fact[i]=f;
	}
	for(i=1;i<=lim;i++)
	{
		inv[i]=mypow(fact[i],mod-2);
	}
	
}
char str[501];
char hash[256];
int main()
{
	int t,i,cnt;
	LLD ans;
	scanf("%d",&t);
	calc();
	while(t--)
	{
		cnt=0;
		scanf("%s",str);
		memset(hash,0,sizeof(hash));
		for(i=0;str[i]!='\0';i++)
		{
			hash[str[i]]++;
		}
		ans=fact[strlen(str)];
		for(i=65;i<=90;i++)
		{
			if(hash[i]>0)
			{
				
				ans=(ans*inv[hash[i]])%mod;
			}
		}
		for(i=97;i<=122;i++)
		{
			if(hash[i]>0)
			{
				ans=(ans*inv[hash[i]])%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}