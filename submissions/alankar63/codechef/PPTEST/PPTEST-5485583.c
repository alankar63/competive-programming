#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int w[101],v[101],i,j,W,n;
		scanf("%d%d",&n,&W);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&v[i],&j,&w[i]);
			v[i]*=j;
		}
		int t[101][101];
		for(i=0;i<=n;i++)
		for(j=0;j<=W;j++)
		{
			if(i==0||j==0)
			t[i][j]=0;
			else if(w[i]<=j)
			t[i][j]=max(v[i]+t[i-1][j-w[i]],t[i-1][j]);
			else
			t[i][j]=t[i-1][j];
		}
		printf("%d\n",t[n][W]);
	}
return 0;
}