#include <stdio.h>
int parent[100005],groupsize[100005];
int findparent(int n)
{
	if(parent[n]==n)
	return n;
	else
	{
		parent[n]=findparent(parent[n]);
		return parent[n];
	}
}
 
int main(void) {
	int ts;
	int n,m,i,j,count,t1,t2;
	long long int ans;
	scanf("%d",&ts);
	while(ts--)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		ans=1;
		count=0;
		for(i=1;i<=n;i++)
		{
			parent[i]=i;
			groupsize[i]=1;
		}
		while(m--)
		{
			scanf("%d",&i);
			scanf("%d",&j);
			t1=findparent(i);
			t2=findparent(j);
			if(t1!=t2)
			{
				parent[t2]=t1;
				groupsize[t1]+=groupsize[t2];
			}
		}
		for(i=1;i<=n;i++)
		{
			if(parent[i]==i)
			{
				count++;
				ans=(ans*(long long int)(groupsize[i]))%1000000007;
			}
		}
		printf("%d %lld\n",count,ans);
	}
	return 0;
}