#include <stdio.h>
 
int main(void) {
	int n,mod=1000000007;
	scanf("%d",&n);
	long long a[100],i,j,k,size;
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	long long dp[101][101]={{0}};
	for(size=1;size<n;size++)//typical matrix chain/obst loops
	{
		for(i=0;i<(n-size);i++)
		{
			j=i+size;
			//lets find valid sequences between [i,j] with range size=size
			//lets not pairup the jth bracket (+x) with any brackets in the range [i,j-1]
			//so all sequences between [i,j-1] will be included as it is
			dp[i][j]=dp[i][j-1];
			for(k=i;k<=j-1;k++)
			{
				if(a[k]<0 && a[k]+a[j]==0 && a[j]>0)//if (-x) type found
				{
					//pair this (-x,x)ie(k,j) bracket with all sequences inside them ie [k+1,j-1]
					//1 is added to account for the null set
					//pair this (-x,x)ie(k,j) bracket with all sequences outside them ie [i,k-1]
					//1 is added to account for the null set
					if(k-1<0)
						dp[i][j] = (dp[i][j]%mod + (dp[k+1][j-1] + 1)%mod)%mod;
					else
						dp[i][j]=((dp[i][j]%mod)+((dp[k+1][j-1]+1)*1LL*(dp[i][k-1]+1))%mod)%mod;
				}
			}
		}
	}
	printf("%lld\n",(dp[0][n-1]+1)%mod);
	return 0;
}