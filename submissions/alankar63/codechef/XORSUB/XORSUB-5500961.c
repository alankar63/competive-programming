#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define mod 100000007

int dp[1025][1025];
//dp[i][j] -> ways to get xor value of j, using
// first i elements of the array A

int A[1025];// B[1025];
//bool inB[1025];
int main()
{int t,n,m,i,j,max;
scanf("%d",&t);
while(t--)
{scanf("%d",&n);
scanf("%d",&m);
for(i=0;i<n;i++)
    scanf("%d",&A[i]);
//memset(inB,0,sizeof(inB));
		//for(j=0;j<m;j++){
			//scanf("%d",&B[j]);
			//inB[B[j]] = true;

		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		max=m;
		for(i=1;i<=n;i++){
			int a = A[i-1];
			for(j=0;j<1024;j++){
				dp[i][j] = dp[i-1][j] + dp[i-1][j^a];
				if(dp[i][j]>=mod)
					dp[i][j] -= mod;
				if(dp[i][j])
                {
                    if((j^m)>max)
                        max=j^m;
                }
			}
		}
    printf("%d\n",max);
}

    return 0;
}