#include <stdio.h>
int par[205],ar[200005];
int min(int x,int y)
{
    if(x==-1)
        return y;
    else
        return x < y ? x : y;
}
int m;
void uni(int x,int y)
{
    int i;
    if (par[x]==par[y])
        return;
    if (par[x]==x)
    {
        for (i = 1; i <=m;i++)
        {
            if(par[i]==par[y] && i!=y)
                par[i]=x;
        }
        par[y]=x;
    }
    else
        uni(par[x],y);
}
int main() {
    int t,k,n,x,y,i,j;
    int dp[205];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&m,&k,&n);
        for (i = 1; i <= m; i++)
        {
            par[i]=i;
        }
        while(k--)
        {
            scanf("%d %d",&x,&y);
            uni(x,y);           
        }
        for (i = 1; i <= n; i++)
            scanf("%d",&ar[i]);
        dp[0]=-1;
        for (i = 1; i <= m; i++)
        {
            dp[i]=dp[i-1];
            if(ar[1]==i)
                dp[i]=0;
            if (par[ar[1]]==par[i] && dp[i]!=0)
                    dp[i]=1;
        }
        
        for (i = 2; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if(dp[j]!=-1)
                {
                        
                        if (par[ar[i]]==par[j])
                        {
                            if(ar[i]==j)
                                dp[j]=min(dp[j-1],dp[j]);
                            else
                                dp[j]=min(dp[j-1],dp[j]+1);
                        }
                        else
                            dp[j]=dp[j-1];
                }
            }
           
        }
        printf("%d\n",dp[m] );
    }
  return 0;
}