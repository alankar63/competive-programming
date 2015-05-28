#include<stdio.h>
#define INT_MAX 1000000
int min(int a,int b){if(a<b)return a;else return b;} 
int t[1001][1001];
int main()
{
	int x;
	scanf("%d",&x);
	while(x--)
	{
		int n,i,j,max=-1;
		scanf("%d",&n);
		int h[501],k[501];
		for(i=0;i<n;i++)
		{
			scanf("%d",&h[i]);
			h[i]*=2;
			if(max<h[i])max=h[i];
		}
		for(i=1;i<=n;i++)	
		scanf("%d",&k[i]);
		t[0][0]=0;
		for(i=1;i<=max;i++)
		t[0][i]=INT_MAX;
		for(i=1;i<=n;i++)
		for(j=0;j<=max;j++)
		{
			if(k[i]<=j)
			t[i][j]=min(1+t[i][j-k[i]],t[i-1][j]);
			else
			t[i][j]=t[i-1][j];
		}
		max=0;
		for(i=0;i<n;i++)
		max+=t[n][h[i]];
		printf("%d\n",max);
	}
return 0;
}