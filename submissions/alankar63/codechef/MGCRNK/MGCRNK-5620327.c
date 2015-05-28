#include <stdio.h>
int max(int a,int b)
{
	return(a>=b?a:b);
}
int main(void) {
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a[n][n];
		int dp[n][n];
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			dp[i][j]=0;
		}
		dp[0][0]=a[0][0];
 
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j>0&&i>0)
				{
					dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i][j-1]);
				}
				else if(i>0&&j==0)
				{
 
					dp[i][j]=a[i][j]+dp[i-1][j];
				}
				else if(j>0&&i==0)
				{
					dp[i][j]=a[i][j]+dp[i][j-1];
				}
			}
		}
 
		float k=(dp[n-1][n-1])/(float)(2*n-3);
		if(dp[n-1][n-1]<0)printf("Bad Judges\n");
		else
		printf("%f\n",k);
 
 
 
 
	}
	return 0;
}